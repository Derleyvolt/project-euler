import math

s = str(int(math.pow(2, 1000)))

ans = 0

for i in s:
    ans = ans + int(i)
print(ans)
