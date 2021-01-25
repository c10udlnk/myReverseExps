# By c10udlnk(https://github.com/c10udlnk)
# Enjoy it!

bfCode=""
with open("brainfuckCode.txt",'r') as f:
    bfCode=f.read()

indent=0
i=0
ptr=0
res=[]
res.append(' '*indent+"mem=[0 for _ in range(0x10000)]\n")
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
        res.append(' '*indent+"mem["+str(ptr)+"]=(mem["+str(ptr)+"]+"+str(cnt)+")&0xFF\n")
    elif bfCode[i]=='-':
        cnt=0
        while bfCode[i]=='-':
            cnt+=1
            i+=1
        res.append(' '*indent+"mem["+str(ptr)+"]=(mem["+str(ptr)+"]-"+str(cnt)+")&0xFF\n")
    elif bfCode[i]=='.':
        res.append(' '*indent+"print(chr(mem["+str(ptr)+"]))\n")
        i+=1
    elif bfCode[i]==',':
        res.append(' '*indent+"mem["+str(ptr)+"]=ord(input(\"Please input a char: \"))\n")
        i+=1
    elif bfCode[i:i+3]=="[-]":
        res.append(' '*indent+"mem["+str(ptr)+"]=0\n")
        i+=3
    elif bfCode[i]=='[':
        res.append(' '*indent+"while mem["+str(ptr)+"]!=0:\n")
        i+=1
        indent+=4
    elif bfCode[i]==']':
        i+=1
        indent-=4
    else:
        print("[-] UknBFCode "+bfCode[i]+" in pos "+str(i)+".\n")
        i+=1

with open("res.py",'w') as f:
    f.writelines(res)