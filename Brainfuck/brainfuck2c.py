# By c10udlnk
# Enjoy it!

bfCode=""
with open("brainfuckCode.txt",'r') as f:
    bfCode=f.read()

indent=0
i=0
ptr=0
res=[]
res.append(' '*indent+"#include <stdio.h>\n")
res.append(' '*indent+"int main(){\n")
indent+=4
res.append(' '*indent+"char mem[0x10000]={0};\n")
while i<len(bfCode):
    if bfCode[i]=='>':
        while bfCode[i]=='>':
            ptr+=1
            i+=1
    elif bfCode[i]=='<':
        while bfCode[i]=='<':
            ptr-=1
            i+=1
    elif bfCode[i]=='+':
        cnt=0
        while bfCode[i]=='+':
            cnt+=1
            i+=1
        res.append(' '*indent+"mem["+str(ptr)+"]+="+str(cnt)+";\n")
    elif bfCode[i]=='-':
        cnt=0
        while bfCode[i]=='-':
            cnt+=1
            i+=1
        res.append(' '*indent+"mem["+str(ptr)+"]-="+str(cnt)+";\n")
    elif bfCode[i]=='.':
        res.append(' '*indent+"printf(\"%c\",mem["+str(ptr)+"]);\n")
        i+=1
    elif bfCode[i]==',':
        res.append(' '*indent+"scanf(\"Please input a char: %c\",&mem["+str(ptr)+"]);\n")
        i+=1
    elif bfCode[i:i+3]=="[-]":
        res.append(' '*indent+"mem["+str(ptr)+"]=0;\n")
        i+=3
    elif bfCode[i]=='[':
        res.append(' '*indent+"while(mem["+str(ptr)+"]){\n")
        i+=1
        indent+=4
    elif bfCode[i]==']':
        i+=1
        indent-=4
        res.append(' '*indent+"}\n")
    else:
        res.append("[-] UknBFCode "+bfCode[i]+" in pos "+str(i)+".\n")
        i+=1
res.append(' '*indent+"return 0;\n")
indent-=4
res.append(' '*indent+"}\n")

with open("res.c",'w') as f:
    f.writelines(res)