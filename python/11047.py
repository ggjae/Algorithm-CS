import sys
n, k = map(int, input().split())
count = 0
num_list = [int(input()) for _ in range(n)]
m=0
num_list = list(reversed(num_list))
for j in range(n):
    if num_list[j] <= k :
        count += k//num_list[j]
        k = k%num_list[j]
print(count)