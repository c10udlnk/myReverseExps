# By c10udlnk (https://github.com/c10udlnk)
# Enjoy it! 0v0

import re

# CHANGE to adapt more pattern
def re_pattern():
    yield r'(v)(\d+)\s*=\s*(-?(?:(?:0x[0-9a-f]+)|\d+))'
    yield r'([A-Za-z0-9]+)\[(\d+)\]\s*=\s*(-?(?:(?:0x[0-9a-f]+)|\d+))'

dataset = {}
maxlen = 100
with open('aProcOfManyEquals.txt', 'r') as f:
    lines = f.readlines()
    for line in lines:
        try:
            g = re_pattern()
            matchObj = None
            while matchObj is None:
                matchObj = re.search(next(g), line)
        except StopIteration:
            print("\033[0;31m[-] Line \"{}\" ERROR!\033[0m".format(line.strip()))
            continue
        name, idx, val = matchObj.groups()
        idx = int(idx)
        # base10 or base16
        try:
            val = int(val)
        except ValueError:
            val = int(val, 16)
        if name not in dataset.keys():
            dataset.update({name:[0, [None for _ in range(maxlen)]]})
        dataset[name][0] = max(dataset[name][0], idx)
        dataset[name][1][idx] = val
# print and ignore extra None(s)
for k, v in dataset.items():
    print(k + " = " + str(v[1][:v[0]+1]))