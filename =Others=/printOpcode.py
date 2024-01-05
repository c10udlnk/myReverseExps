# By c10udlnk (https://github.com/c10udlnk)
# Enjoy it! 0v0

import opcode
for i, j in enumerate(opcode.opname):
    print("0x%02x(%03d): %s" % (i, i, j))