import re

setter = set()
spisok = []

f = open('C://packages.txt') #C://
file = re.findall(r'\d+', text)
for line in file:
    setter.add(int(line))
    if line not in spisok:
        spisok.append(int(line))
        spisok.sort()
    if len(spisok)==1:
        print("Нет потерянных пакетов!")
    else:
        print("Потерянные пакеты:")
        print(setter.symmetric_difference(range(spisok[0],spisok[len(spisok)-1]+1)))