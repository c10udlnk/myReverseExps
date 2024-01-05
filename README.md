# myReverseExps

> By c10udlnk(https://github.com/c10udlnk)

自己总结编写的一些逆向常用脚本&&常见加密/编码的实现源码和比赛时用的处理脚本。

P.S. 鲁棒性不强，请保证使用时都是规范的，不然输出有问题就不是我的锅（逃。

对于各部分，readme按照其各子部分的首字母顺序进行排序。

持续更新ing...

## 逆向

### Angr

运用[angr](https://c10udlnk.top/2020/11/11/logFor-Angr-CTF/)爆破某些二进制文件（极简用法。

- `myAngr.py`：angr脚本，需修改path_to_binary（文件路径）和相应参数（比如find_address之类的）。

### Brainfuck

将[Brainfuck](https://en.wikipedia.org/wiki/Brainfuck)源码转换为易懂的高级语言代码，在`bfCode.bf`中输入brainfuck代码，运行相应的文件即可。

需修改`brainfuck2HLPL_c.py`中`set_HLPL_syntax()`函数中的配置以适应所需语言的语法。

- `bfCode.bf`：Brainfuck源码。

- `brainfuck2HLPL_c.py`：将Brainfuck转换为高级语言代码，以C语言为例，存入`res.c`中。

- `res.c`：上述处理的结果输出。

- `brainfuck2HLPL_py.py`：将Brainfuck转换为高级语言代码，以Python为例，存入`res.py`中。

- `res.py`：上述处理的结果输出。

### IDAprocess

#### aProcOfManyEquals

还原代码中乱序赋值的数组，支持形如`list[6] = 22`、`v11 = 0x3`的赋值整理。

- `aProcOfManyEquals/aProcOfManyEquals.txt`：一些连续赋值的变量（实际上是为了混淆而拆开的数组）。
- `aProcOfManyEquals/aProcOfManyEquals.py`：输出由`aProcOfManyEquals.txt`还原的数组，支持多数组整合。

#### IDAPython｜patch_SMC

处理xor的SMC文件时的patch脚本，在IDA中File->Script file，导入脚本运行即可。

- `IDAPython/patch_SMC.py`：需修改相应的codeStart（smc起始地址）、codeLen（长度）和xorData（用来xor的key）。运行后在函数首地址按`p`转函数即可。

#### IDAPython｜nop_JunkCode

Nop花指令时的patch脚本，在IDA中File->Script file，导入脚本运行即可。

- `IDAPython/nop_JunkCode.py`：需将l修改成相应的花指令类型，并按需修改start_addr和end_addr。运行后在函数首地址按`p`转函数即可。

### VMprotect

vm（虚拟机）题的辅助翻译机，在分析完各opcode的作用以后填入python文件中，生成伪代码。

- `VMinterpreter.py`：将各opcode的作用语句按格式填入ins_set中，再将程序中获得的opcode填入opcode列表中，运行即可。如有需要特殊处理的opcode，请填入elif中。最后伪代码输出到`assembly.txt`。

- `assembly.txt`：上述处理的结果输出。

- `printf_VMinterpreter.py`：翻译[自定义printf](https://www.gnu.org/software/libc/manual/html_node/Customizing-Printf.html)的printf虚拟机，将fm赋值为程序中的格式字符串，各格式占位符的作用语句填入ins_set中。如有特殊符号正则没有提取到，按需修改ptn。try中对参数的选取也要按题目实现进行修改，本例中的参数选择题目中的伪代码为：

  ```c
  __int64 __fastcall func(FILE *stream, const struct printf_info *info, const void *const *args)
  {
    // ...
    width = info->width;
    prec = info->prec;
    if ( (*((_BYTE *)info + 12) & 0x20) != 0 ) //info -> left
    {
      v6 = &format[width];
    }
    else if ( (*((_BYTE *)info + 12) & 0x40) != 0 ) //info -> showsign
    {
      v6 = &format[reg[width]];
    }
    else
    {
      v6 = (char *)&reg[width];
    }
    v7 = 0LL;
    if ( (*((_BYTE *)info + 13) & 2) != 0 ) //info->is_char
    {
      v7 = *(int *)&format[prec];
    }
    else if ( (*((_BYTE *)info + 12) & 2) != 0 ) //info->is_short
    {
      v7 = *(int *)&format[reg[prec]];
    }
    else if ( (*((_BYTE *)info + 12) & 1) != 0 ) //info->is_long_double
    {
      v7 = prec;
    }
    else if ( (*((_BYTE *)info + 12) & 4) != 0 ) //info->is_long
    {
      v7 = reg[prec];
    }
    // opcode, e.g. movq
    *(_QWORD *)v6 = v7;
    return 0LL;
  }
  ```

  最后伪代码输出到`printf_assembly.txt`。

- `printf_assembly.txt`：上述处理的结果输出。

### =Others=

其他一些稀奇古怪的小脚本。

- `printOpcode.py`：输出当前Python版本所有的opcode及对应助记符。
- `bin2db.py`：64位二进制转double（小数）。
- `myPwn.py`：自用PWN交互脚本。
- `pexpect_Ix.py`：使用pexpect进行批量交互，可以在打开文件后持续输入输出（类似pwntools）。
- `maze_bfs.py`：maze（迷宫题）的BFS解法。使用前需修改迷宫地图属性（地图maze、行r、列c）、起点和终点（start、end）、行走控制字符（FLAG_CHAR）、可通过条件。
- ……

## 各种编码&哈希&密码

相关脚本存放于`./_CRYPTO_`文件夹中，以下仍然按照字母排序。

一些工具：

- `Generate_inv_SBox.py`：S盒被魔改时，可用于生成逆S盒。

### 编码算法

#### Base64

- `Base64/transBase64.py`：Base64标准编码/解码，增加换表功能。换表需要将myTable修改成使用的表，如不需要换表则可以在调用trans_Ba64encode/trans_Ba64decode时第二个参数留空。

### 哈希算法

#### MD5

> 参考链接：
>
> 1. [C语言实现md5函数代码\_xhhjin的专栏-CSDN博客_c语言md5](https://blog.csdn.net/xhhjin/article/details/8450686)
>2. [pod32g/MD5: C implementation of the MD5 algorithm](https://github.com/pod32g/MD5)

- `MD5/MD5.c`：日常逆向最常见到的MD5写法（参考链接-1）。
- `MD5/MD5`：由`MD5.c`编译而来，可以用IDA pro打开以对比逆向代码。
- `MD5/MD5_std.c`：常规MD5写法（参考链接-2）。
- `MD5/MD5_std`：由`MD5_std.c`编译而来，可以用IDA pro打开以对比逆向代码。
- `MD5/MD5.py`：使用封装的MD5函数进行MD5值计算。



### 现代密码算法

#### DES

> 参考链接：
>
> [DES算法实例详解-码农场](http://www.hankcs.com/security/des-algorithm-illustrated.html)

- `DES/DES.cpp`：DES加解密算法实现源码。
- `DES/DES.py`：使用封装的DES函数进行加解密。
- `DES/DES`：由`DES.cpp`编译而来，可以用IDA pro打开以对比逆向代码。

#### RC4

> 参考链接：
>
> [恶意代码分析之 RC4 算法学习 - 知乎](https://zhuanlan.zhihu.com/p/102245260)

- `RC4/RC4.cpp`：RC4加解密算法实现源码。
- `RC4/RC4.py`：使用封装的RC4函数进行加解密。
- `RC4/RC4`：由`RC4.cpp`编译而来，可以用IDA pro打开以对比逆向代码