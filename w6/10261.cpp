#include <iostream>
#include <string.h>
using namespace std;

char dp[201][10001];
char r[201][10001];

int main() {
    int n;
    cin >> n;

    while (n--) {
        int length;
        cin >> length;
        length *= 100;

        int count = 1;
        int carLength[205], sum[205];
        int cl;
        while (scanf("%d", &cl), cl) {
            if (count < 201) {
                carLength[count] = cl;
                sum[count] = sum[count-1] + carLength[count];
                count++;
            }
        }

        int maxCar = 0;
        int maxLen = 0;

        memset(dp, 0, sizeof(dp));
        memset(r, 0, sizeof(r));
        
        dp[0][0] = 1;

        //dp[car][length on one side]
        for (int i = 1; i < count; i++) {
            for (int j = 0; j <= length; j++) {
                if (j >= carLength[i] && dp[i-1][j-carLength[i]]) {
                    maxCar = i;
                    maxLen = j;
                    dp[i][j] = 1;
                    r[i][j] = 0;
                }
                if (sum[i] - j <= length && dp[i-1][j]) {
                    maxCar = i;
                    maxLen = j;
                    dp[i][j] = 1;
                    r[i][j] = 1;
                }
            }

            if (maxCar != i) {
                break;
            }
        }

        cout << maxCar << endl;

        int i = maxCar;
        int j = maxLen;
        int pos[maxCar+1];
        while (i) {
            pos[i] = r[i][j];
            if (!r[i][j]) {
                j -= carLength[i];
            }
            i--;
        }

        for (int i = 1; i <= maxCar; i++) {
            if (pos[i]) {
                cout << "starboard" << endl;
            } else {
                cout << "port" << endl;
            }
        }

        if (n) {
            cout << endl;
        }
    }

    return 0;
}