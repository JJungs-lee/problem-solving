A, B = map(int, input().split())

arr = []
for i in range(100):
    for j in range(i):
        arr.append(i)
        # A, B 둘 다 최대 값이 1000이므로 arr의 길이가 1000이 되면 탈출
        if len(arr) == 1000: 
            break
    if len(arr) == 1000:
        break

print(sum(arr[A-1 : B]))