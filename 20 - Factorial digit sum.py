N = 100

ret = 1

for i in range(1, N+1):
	ret = (ret * i)

ret = 0

for i in str(ret):
	# print(ord(i)-ord('0'), end='')
	ret = ret + ord(i)-ord('0')

print(ret)
