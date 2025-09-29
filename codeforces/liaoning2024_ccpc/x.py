n = int(input())
a, ans = 1, 0
for i in range(1, n):
    a *= i
    ans += a
print(ans)