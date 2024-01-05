# By c10udlnk(https://github.com/c10udlnk)
# Enjoy it!

import base64

b64table = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
myTable = "0123456789QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm+/"

def trans_Ba64encode(src, table=b64table):
    assert len(table) == 64
    dest = base64.b64encode(src).decode().translate(str.maketrans(b64table, table))
    return dest

def trans_Ba64decode(src, table=b64table):
    assert len(table) == 64
    dest = base64.b64decode(src.translate(str.maketrans(table, b64table)))
    return dest

text = "HefBHzpjJ6whFlwhFl5CHefBHzj="
print("[*] text:", text)
text = trans_Ba64decode(text, myTable)
print("[-] trans_Ba64decode:", text)

print("\n[*] text:", text)
text = trans_Ba64encode(text, myTable)
print("[+] trans_Ba64encode:", text)