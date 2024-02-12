//queue people

#include <iostream>
using namespace std;

int main() {
    int c;
    scanf("%d", &c);
    
    int dp[15][15][15] = {0};
    dp[1][1][1] = 1; // dp[people][front][back]
    for (int i = 2; i <= 13; i++) {
        for (int j = 1; j <= i; j++) {
            for (int k = 1; k <= i; k++) {
                dp[i][j+1][k] += dp[i-1][j][k];
                dp[i][j][k+1] += dp[i-1][j][k];
                dp[i][j][k] += dp[i-1][j][k]*(i-2);
            }
        }
    }

    while (c--) {
        int n, f, b;
        scanf("%d%d%d", &n, &f, &b);

        printf("%d\n", dp[n][f][b]);
    }

    return 0;
}