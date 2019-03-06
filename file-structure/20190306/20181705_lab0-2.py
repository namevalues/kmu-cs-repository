data = [90, 40, 60, 10, 50, 80, 20, 70]
max = 0
min = 100
max_index=0
min_index=0

for idx,i in enumerate(data):
    if max < i:
        max = i
        max_index = idx
    if min > i:
        min = i
        min_index = idx

print('Minimum number is',min,'at position',min_index+1)
print('Maximum number is',max,'at position',max_index+1)

