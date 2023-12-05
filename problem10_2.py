import re

def to_i(a):
    return [int(x) for x in a.split(" ") if x]

with open("problem11.txt", "r") as file:
    lines = file.readlines()

lines = [elt.strip() for elt in lines if re.search("[^\n|]", elt)]
