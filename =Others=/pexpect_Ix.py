# By c10udlnk (https://github.com/c10udlnk)
# Enjoy it! 0v0

import pexpect

for i in range(1, 60):
    r = pexpect.spawn("python2", [str(i)+".py"])
    r.sendline(str(i) + ".png")
    r.readline()
    r.readline()
    exper = r.readline()[:-6]
    r.sendline(str(eval(exper)))
    r.close()