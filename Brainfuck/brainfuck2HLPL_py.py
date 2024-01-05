# By c10udlnk (https://github.com/c10udlnk)
# Enjoy it! 0v0

# read brainfuck code
bfCode = ""
with open("bfCode.bf", 'r') as f:
    bfCode = f.read()

# init globals
i = 0
ptr = 0
indent = 0
SYNTAX = {}
bfCodeLen = len(bfCode)

# CHANGE this function to set the syntax of the output HLPL
# Python for example
# be careful of format's "{" and "}"
def set_HLPL_syntax():
    global SYNTAX
    global indent
    SYNTAX['ext'] = ".py"
    SYNTAX['start'] = \
        "import sys\n\n" \
        "mem = [0 for _ in range(0x10000)]\n"
    SYNTAX['+'] = "{_indent}mem[{_ptr}] = (mem[{_ptr}]+{_cnt}) & 0xff\n"
    SYNTAX['-'] = "{_indent}mem[{_ptr}] = (mem[{_ptr}]-{_cnt}) & 0xff\n"
    SYNTAX['.'] = "{_indent}print(chr(mem[{_ptr}]))\n"
    SYNTAX[','] = "{_indent}mem[{_ptr}] = ord(sys.stdin.read(1))\n"
    SYNTAX['[-]'] = "{_indent}mem[{_ptr}] = 0\n"
    SYNTAX['['] = "{_indent}while mem[{_ptr}] != 0:\n"
    SYNTAX[']'] = ""
    SYNTAX['end'] = \
        ""

set_HLPL_syntax()
output = open('res'+SYNTAX['ext'], 'w')
output.write(SYNTAX['start'].format(_indent=' '*indent)) # CHANGE

while i < bfCodeLen:
    if bfCode[i] == '>':
        while i < bfCodeLen and bfCode[i] == '>':
            ptr += 1
            i += 1
    elif bfCode[i] == '<':
        while i < bfCodeLen and bfCode[i] == '<':
            ptr -= 1
            i += 1
    elif bfCode[i] == '+':
        cnt = 0
        while i < bfCodeLen and bfCode[i] == '+':
            cnt += 1
            i += 1
        output.write(SYNTAX['+'].format(_indent=' '*indent, _ptr=ptr, _cnt=cnt))
    elif bfCode[i] == '-':
        cnt = 0
        while i < bfCodeLen and bfCode[i] == '-':
            cnt += 1
            i += 1
        output.write(SYNTAX['-'].format(_indent=' '*indent, _ptr=ptr, _cnt=cnt))
    elif bfCode[i] == '.':
        output.write(SYNTAX['.'].format(_indent=' '*indent, _ptr=ptr))
        i += 1
    elif bfCode[i] == ',':
        output.write(SYNTAX[','].format(_indent=' '*indent, _ptr=ptr))
        i += 1
    elif bfCode[i:i+3] == '[-]':
        output.write(SYNTAX['[-]'].format(_indent=' '*indent, _ptr=ptr))
        i += 3
    elif bfCode[i] == '[':
        output.write(SYNTAX['['].format(_indent=' '*indent, _ptr=ptr))
        i += 1
        indent += 4
    elif bfCode[i] == ']':
        i += 1
        indent -= 4
    else:
        print("\033[0;31m[-] UknBFCode {_code} in pos {_pos}.\033[0m".format(_code=bfCode[i], _pos=i))
        i += 1

output.close()

# check if indents return to 0
assert indent == 0