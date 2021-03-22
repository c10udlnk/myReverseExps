# By c10udlnk(https://github.com/c10udlnk)
# Enjoy it!

from Crypto.Cipher import DES
import binascii

key=binascii.unhexlify("133457799bbcdff1")
des=DES.new(key,DES.MODE_ECB)

###### Encryption ######
text=binascii.unhexlify("0123456789abcdef")
cipher=des.encrypt(text)
print("\n[+]DES Encrypt result: "+binascii.hexlify(cipher).decode())
print(cipher)

###### Decryption ######
cipher=binascii.unhexlify("85e813540f0ab405")
text=des.decrypt(cipher)
print("\n[-]DES Decrypt result: "+binascii.hexlify(text).decode())
print(text)