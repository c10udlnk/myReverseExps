# By c10udlnk (https://github.com/c10udlnk)
# Enjoy it! 0v0

def xorPatch(start, end, key):
    addr = start
    while addr != end + 1:
        PatchByte(addr, Byte(addr) ^ key)
        MakeUnkn(addr, 0x90)
        addr += 1
    print("%d Byte has been changed" % (addr-start))

codeStart = 0x600B00
codeLen = 182
# codeEnd = 0x600bb5
# codeLen = codeEnd - codeStart + 1
xorData = 0xC
xorPatch(codeStart, codeStart+codeLen-1, xorData)