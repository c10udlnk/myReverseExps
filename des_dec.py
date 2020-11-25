from Crypto.Cipher import DES
from binascii import hexlify

k=b'666C6167'
c=b'\x99\xED\xA1\xD9\x41\x31\x6E\xEA'
enc=DES.new(k,DES.MODE_ECB)
text=enc.decrypt(c)

print(text)
print(hexlify(text).decode())