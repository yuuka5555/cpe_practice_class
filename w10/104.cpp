#include <bits/stdc++.h>
using namespace std;

int n;
double convert[25][25][25];
int pre[25][25][25];

void output(int t, int i, int j) {
    if (t >= 1) {
        output(t-1, i, pre[t][i][j]);
        cout << " " << j;
    } else {
        cout << i;
    }
}

bool dp() {
    for (int t = 2; t <= n; t++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                convert[t][i][j] = -1.0;
                for (int k = 1; k <= n; k++) {
                    if (convert[t][i][j] < convert[t-1][i][k]*convert[1][k][j]) {
                        pre[t][i][j] = k;
                        convert[t][i][j] = convert[t-1][i][k]*convert[1][k][j];
                    }
                }
            }

            if (convert[t][i][i] > 1.01) {
                output(t, i, i);
                return true;
            }
        }
    }

    return false;
}

int main() {
    while (cin >> n) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) {
                    convert[1][i][j] == 1.0;
                } else {
                    cin >> convert[1][i][j];
                }
            }
        }

        if (!dp()) {
            cout << "no arbitrage sequence exists";
        }
        cout << endl;
    }

    return 0;
}