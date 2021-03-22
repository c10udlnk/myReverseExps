# myReverseExps

> By c10udlnk(https://github.com/c10udlnk)

自己总结编写的一些逆向常用脚本&&常见加密/编码的实现源码和比赛时用的处理脚本。

P.S. 鲁棒性不强，请保证使用时都是规范的，不然输出有问题就不是我的锅（逃。

对于各部分，readme按照其各子部分的首字母顺序进行排序。

持续更新ing...

## 逆向

### Angr

运用[angr](https://c10udlnk.top/2020/11/11/logFor-Angr-CTF/)爆破某些二进制文件。

- `myAngr.py`：angr脚本，需修改path_to_binary（文件路径）和相应参数（比如find_address之类的）。

### Brainfuck

将[Brainfuck](https://en.wikipedia.org/wiki/Brainfuck)源码转换为易懂的C或者python代码，在`bfCode.bf`中输入brainfuck代码，运行相应的文件即可。

建议转换为C，相比之下Python在处理char型数据时会冗杂很多。

另外C++和C差不多就不另写了（

- `bfCode.bf`：Brainfuck源码。

- `brainfuck2c.py`：将Brainfuck转换为C语言代码，存入`res.c`中。

- `brainfuck2py.py`：将Brainfuck转换为python代码，存入`res.py`中。

### IDAprocess

- `aProcOfManyEquals.txt`：一些连续赋值的变量（实际上是数组，为了混淆拆开了）。
- `aProcOfManyEquals.py`：输出由`aProcOfManyEquals.txt`还原的数组。

### SMC

处理异或的SMC文件时的patch脚本，在IDA中File->Script file，导入脚本运行即可。

- `patch_SMC.py`：patch脚本，需修改相应的codeStart（smc起始地址）、codeLen（长度）和xorData（用来xor的key）。

### VMprotect

vm（虚拟机）题的辅助翻译机，在分析完各opcode的作用以后填入python文件中，生成伪代码。

- `VMinterpreter.py`：将各opcode的作用语句按格式填入ins_set中，再将程序中获得的opcode填入opcode列表中，运行即可。如有需要特殊处理的opcode，请填入elif中。最后伪代码输出到`res.txt`。

## 加解密&编码

加解密及编码算法相关脚本存放于`./_CRYPTO_`文件夹中。

### DES

> 参考链接：[DES算法实例详解-码农场](http://www.hankcs.com/security/des-algorithm-illustrated.html)

- `DES.cpp`：DES加解密算法实现源码。
- `DES.py`：使用封装的DES函数进行加解密。
- `DES`：由`DES.cpp`编译而来，可以用IDA pro打开以对比逆向代码。

### RC4

> 参考链接：[恶意代码分析之 RC4 算法学习 - 知乎](https://zhuanlan.zhihu.com/p/102245260)

- `RC4.cpp`：RC4加解密算法实现源码。
- `RC4.py`：使用封装的RC4函数进行加解密。
- `RC4`：由`RC4.cpp`编译而来，可以用IDA pro打开以对比逆向代码