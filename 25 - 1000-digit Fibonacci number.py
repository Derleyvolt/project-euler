import math

ls = [None] * 1000000

ls[0] = 1;
ls[1] = 1;

cnt = 2

## Existe uma abordagem matemática pra resolver esse problema de maneira mais elegante e com complexidade infinitamente melhor. Dps vejo ela.

## brute force, eca..
while True:
    ls[cnt] = ls[cnt-1] + ls[cnt-2]
    if len(str(ls[cnt])) >= 1000:
        print(i)
        break
    cnt += 1
