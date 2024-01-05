# By c10udlnk(https://github.com/c10udlnk)
# Enjoy it!

from Crypto.Cipher import DES
import binascii

key = binascii.unhexlify("")
des = DES.new(key,DES.MODE_ECB)

###### Decryption ######
cipher = binascii.unhexlify("0f88b8529ab6c0dd2b5ceefaa1c5151aa207da114831b371ddcafc74cf8701c1d3318468d50e4b1725179d1bc04b251f")
text = des.decrypt(cipher)
print("\n[-]DES Decrypt result: " + binascii.hexlify(text).decode())
print(text)