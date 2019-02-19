import re

setter = set()
spisok = []

file = open('C:\\packages.txt')
text = file.read()
data = re.findall(r'\d+', text)

for line in data:
    setter.add(int(line))
    if line not in spisok:
        spisok.append(int(line))
        spisok.sort()
    if len(spisok)==1:
        print("No lost packages!")
    else:
        print("Lost packages:")
        print(setter.symmetric_difference(range(spisok[0],spisok[len(spisok)-1]+1)))