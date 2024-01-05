# By c10udlnk(https://github.com/c10udlnk)
# Enjoy it!

from hashlib import md5

data = b'flagflagflagflag'
flag = md5(data).hexdigest()

print(flag)