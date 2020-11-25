from arc4 import ARC4
from binascii import hexlify

key='flag'
code=b'\x99e\xf4H)\x90\xa9\x8f'
enc=ARC4(key)
text=enc.encrypt(code)

print(text)
print(hexlify(text).decode())