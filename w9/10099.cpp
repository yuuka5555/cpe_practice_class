#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, scenario = 1;
    while (cin >> n >> m) {
        if (n == 0) break;

        int g[105][105] = {0};
        for (int i = 0; i < m; i++) {
            int p1, p2, c;
            cin >> p1 >> p2 >> c;
            g[p1][p2] = g[p2][p1] = c;
        }

        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    g[i][j] = max(g[i][j], min(g[i][k], g[k][j]));
                }
            }
        }

        int s, d, p;
        cin >> s >> d >> p;
        cout << "Scenario #" << scenario++ << endl;
        int cost = p / (g[s][d]-1);
        if (p % (g[s][d]-1) > 0) {
            cost++;
        }
        cout << "Minimum Number of Trips = " << cost << endl;
        cout << endl;
    }

    return 0;
}