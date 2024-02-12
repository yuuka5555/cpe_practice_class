t = int(input())
while(t):
    t -= 1
    s1 = " "
    s2 = " "
    s1 += str(input())
    s2 += str(input())
    dp = [[0 for i in range (len(s1)+1)]for j in range(len(s2)+1)]
    for i in range(len(s1)):
        dp[0][i] = 1
    for i in range(1,len(s2)):
        for j in range(1,len(s1)):
            if s2[i] == s1[j]:
                dp[i][j] = dp[i-1][j-1] + dp[i][j-1]
            else:
                dp[i][j] = dp[i][j-1]

    print(dp[len(s2)-1][len(s1)-1])