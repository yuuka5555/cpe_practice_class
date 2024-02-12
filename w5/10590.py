max = 5001
dp = [0 for i in range(max)]

def build() :
    dp[0] = 1
    for i in range(1, max) :
        for j in range(i, max) :
            dp[j] += dp[j-i]

build()
while True :
    try :
        n = int(input())
        print(dp[n])
    except EOFError :
        break