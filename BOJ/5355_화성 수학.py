import sys

read = sys.stdin.readline
tc = int(read())

while (tc):
    arr = read().split()
    num = float(arr[0])

    for i in range(1, len(arr)):
        if arr[i] == '@':
            num *= 3
        elif arr[i] == '%':
            num += 5
        elif arr[i] == '#':
            num -= 7
    print("{:.2f}".format(num))

    tc -= 1
