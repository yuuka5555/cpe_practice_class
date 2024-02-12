dp = [[0 for a in range(151)] for a in range(151)]
vis = [[0 for a in range(151)] for a in range(151)]

def DP(n:int, d:int)->int :
    if vis[n][d] :
        return dp[n][d]
    
    vis[n][d] = 1
    
    if n == 0 :
        dp[n][d] = 1
        return 1
    elif n > 0 and d == 0 :
        dp[n][d] = 0
        return 0
    else :
        for i in range(n) :
            dp[n][d] += DP(i, d-1) * DP(n-i-1, d)

    return dp[n][d]

while True :
    try :
        nd = str(input())
        n, d = nd.split()
        n = int(n)
        n //= 2
        d = int(d)

        print(DP(n, d) - DP(n, d-1))
    except EOFError :
        break