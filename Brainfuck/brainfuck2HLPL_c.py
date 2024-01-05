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
# C for example
# be careful of format's "{" and "}"
def set_HLPL_syntax():
    global SYNTAX
    global indent
    SYNTAX['ext'] = ".c"
    SYNTAX['start'] = \
        "#include <stdio.h>\n\n" \
        "int main() {{\n" \
        "{_indent}char mem[0x10000] = {{0}};\n"
    SYNTAX['+'] = (1, 0, "{_indent}mem[{_ptr}] += {_cnt};\n")
    SYNTAX['-'] = (1, 0, "{_indent}mem[{_ptr}] -= {_cnt};\n")
    SYNTAX['.'] = (1, 0, "{_indent}printf(\"%c\", mem[{_ptr}]);\n")
    SYNTAX[','] = (1, 0, "{_indent}mem[{_ptr}] = getchar();\n")
    SYNTAX['[-]'] = (3, 0, "{_indent}mem[{_ptr}] = 0;\n")
    SYNTAX['['] = (1, 4, "{_indent}while(mem[{_ptr}]) {{\n")
    SYNTAX[']'] = (1, -4, "{_indent}}}\n")
    SYNTAX['end'] = \
        "{_indent}return 0;\n" \
        "}}\n"

set_HLPL_syntax()
output = open('res'+SYNTAX['ext'], 'w')
indent += 4 # CHANGE
output.write(SYNTAX['start'].format(_indent=' '*indent)) # CHANGE

while i < bfCodeLen:
    if bfCode[i] == '>' or bfCode[i] == '<':
        op = bfCode[i]
        mov = 1 if op == '>' else -1
        while i < bfCodeLen and bfCode[i] == op:
            ptr += mov
            i += 1
    elif bfCode[i] == '+' or bfCode[i] == '-':
        cnt = 0
        op = bfCode[i]
        while i < bfCodeLen and bfCode[i] == op:
            cnt += 1
            i += 1
        output.write(SYNTAX[op][2].format(_indent=' '*indent, _ptr=ptr, _cnt=cnt))
    elif bfCode[i:i+3] == '[-]':
        output.write(SYNTAX['[-]'][2].format(_indent=' '*indent, _ptr=ptr))
        i += SYNTAX['[-]'][0]
    elif bfCode[i] in ['.', ',', '[']:
        op = bfCode[i]
        output.write(SYNTAX[op][2].format(_indent=' '*indent, _ptr=ptr))
        i += SYNTAX[op][0]
        indent += SYNTAX[op][1]
    elif bfCode[i] == ']':
        op = bfCode[i]
        i += SYNTAX[op][0]
        indent += SYNTAX[op][1]
        output.write(SYNTAX[']'][2].format(_indent=' '*indent, _ptr=ptr))
    else:
        print("\033[0;31m[-] UknBFCode {_code} in pos {_pos}.\033[0m".format(_code=bfCode[i], _pos=i))
        i += 1

output.write(SYNTAX['end'].format(_indent=' '*indent)) # CHANGE
indent -= 4 # CHANGE
output.close()

# check if indents return to 0
assert indent == 0