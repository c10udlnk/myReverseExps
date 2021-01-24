def aPatch(start,end,key):
    n=0
    while(start+n!=end+1):
        addr=start+n
        PatchByte(addr,Byte(addr)^key)
        n+=1
    print("%d Byte has been changed"%n)

codeStart=0x600B00
codeLen=182
xorData=0xC
aPatch(codeStart,codeStart+codeLen-1,xorData)