# By c10udlnk (https://github.com/c10udlnk)
# Enjoy it! 0v0

start_addr = 0x00412CC0
end_addr = 0x00413991
l = [0x74, 0x03, 0x75, 0x01, 0xE8]

def myNop(addr, end):
    while addr < end:
        for i in range(len(l)):
            if idc.get_wide_byte(addr + i) != l[i]:
                addr += 1
                break
        else:
            for i in range(len(l)):
                patch_byte(addr, 0x90)
                addr += 1
    print("[+] nop ok!!")

myNop(start_addr, end_addr)
#批量undefined
del_items(start_addr, 0, end_addr-start_addr+1)
# for i in range(start_addr, end_addr + 1):
#     MakeUnkn(i, 0x90)