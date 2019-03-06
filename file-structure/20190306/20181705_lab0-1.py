f = open('lab0-1.dat','r')
lines = f.readlines()
sum = int(0)

for line in lines:
    print(line)
    a = int(0)
    b = int(0)
    state = 'OUT'

    for i in line:
        if i.isalpha:
            if state == 'OUT':
                a += 1
                state = 'IN'
        if i == ' ':
            state = 'OUT'
            b += 1

    sum += a
    print('The number of words :',a)
print('Total Number of Words:',sum)
