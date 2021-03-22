# By c10udlnk(https://github.com/c10udlnk)
# Enjoy it!

from arc4 import ARC4
import binascii

key=binascii.unhexlify(b"746831735f31735f6b33792121212121")
data=binascii.unhexlify(b"8bd2d95d95ff7e5f295612b9efec8bd045")
rc4=ARC4(key)
ans=rc4.encrypt(data)

print(binascii.hexlify(ans))
# print(ans)