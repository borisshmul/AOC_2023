import re

def to_i(a):
    return [int(x) for x in a.split(" ") if x]

with open("problem11.txt", "r") as file:
    lines = file.readlines()

lines = [elt.strip() for elt in lines if re.search("[^\n|]", elt)]

seeds = [int(x) for x in lines[0].split(":")[-1].split(" ") if x]

map = []
tmp = []
for elt in lines[2:]:
    if re.match("^\d+( \d+)*$", elt):  # Matches lines with numbers
        tmp.append(to_i(elt))
    elif elt.endswith('map:'):
        if tmp:
            map.append(tmp)
            tmp = []
if tmp:  # Add the last map if there's any
    map.append(tmp)

res = []
for seed in seeds:
    transformed_seed = seed
    for mp in map:
        for j in mp:
            offset = transformed_seed - j[1]
            if 0 <= offset <= j[2]:
                transformed_seed = j[0] + offset
                break
    res.append(transformed_seed)

print(min(res))
