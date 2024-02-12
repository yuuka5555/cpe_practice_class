#include <iostream>
#include <string.h>

char a[25], b[25];
int dp[100][100], op[100][100];

void pr(int i, int j) {
    if(i == 0 && j == 0)    return;
    if(op[i][j] == 1)
        pr(i-1, j-1);
    else if(op[i][j] == 2) {
        pr(i-1, j);
        printf("D%c%02d", a[i-1], j+1);
    }
    else if(op[i][j] == 3) {
        pr(i, j-1);
        printf("I%c%02d", b[j-1], j);
    } else {
        pr(i-1, j-1);
        printf("C%c%02d", b[j-1], j);
    }

}

int main() {
    int i, j;
    while(scanf("%s", a)) {
        if (a[0] != '#') {
            scanf("%s", b);
        } else {
            break;
        }
        
        memset(dp, 63, sizeof(dp));

        int la = strlen(a), lb = strlen(b);
        
        dp[0][0] = 0;
        for(i = 0; i <= la; i++) {
            for(j = 0; j <= lb; j++) {
                if(a[i] == b[j] && dp[i+1][j+1] > dp[i][j]) { // copy
                    dp[i+1][j+1] = dp[i][j], op[i+1][j+1] = 1;
                }
                if(dp[i+1][j] > dp[i][j]+1) { // del
                    dp[i+1][j] = dp[i][j]+1; op[i+1][j] = 2;
                }
                if(dp[i][j+1] > dp[i][j]+1) { // ins
                    dp[i][j+1] = dp[i][j]+1; op[i][j+1] = 3;
                }
                if(dp[i+1][j+1] > dp[i][j]+1) { // change
                    dp[i+1][j+1] = dp[i][j]+1; op[i+1][j+1] = 4;
                }
            }
        }
        pr(la, lb);
        printf("E\n");
    }
    return 0;
}