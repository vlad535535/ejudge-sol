import math

def comb(n, k):
    return math.factorial(n)//(math.factorial(k)*math.factorial(n-k))

f = open('paint.dat', 'r')
k, n = map(int, f.read().split())
f.close()
ans = comb(k, 4)*24
t = ans
n -= 1
while n > 0:
    ans *= t - 1
    n -= 1
f = open('paint.sol', 'w')
f.write(str(ans))
f.close()