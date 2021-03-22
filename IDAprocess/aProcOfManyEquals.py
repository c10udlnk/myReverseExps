# By c10udlnk(https://github.com/c10udlnk)
# Enjoy it!

data=[]
with open('aProcOfManyEquals.txt','r') as f:
    lines=f.readlines()
    for line in lines:
        tmpStr=line.replace(' ','').replace('\n','')
        equalIndex=tmpStr.index('=')
        tmpData=tmpStr[equalIndex+1:-1]
        data.append(int(tmpData))
print(data)