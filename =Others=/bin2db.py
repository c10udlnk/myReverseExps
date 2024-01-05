# By c10udlnk (https://github.com/c10udlnk)
# Enjoy it! 0v0

def int64_to_double(t):
    s = bin(t)[2:].zfill(64)
    sign = 1 if s[0] == '0' else -1
    n = int(s[1:12], 2)
    tmp = 1
    ans = 1
    for i in range(len(s[12:])):
        tmp /= 2
        if s[12:][i] == '1':
            ans += tmp
    return sign * ans * (2 ** (n - 2 ** 10 + 1))

print(int64_to_double(0x4000000000000000))
print(int64_to_double(0x4010000000000000))
print(int64_to_double(0x4018000000000000))
print(int64_to_double(0x3FF0000000000000))
print(int64_to_double(0x4005BF0A8B145769))

# 2
# 4
# 6.0
# 1
# 2.718281828459045