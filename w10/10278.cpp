#include <bits/stdc++.h>
#define Inf 10000000;
using namespace std;

int kase, f, n;
int itnum[505];
int m[505][505];
string in;

void floy() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (m[i][j] > m[i][k] + m[k][j]) {
                    m[i][j] = m[i][k] + m[k][j];
                }
            }
        }
    }
}

void initial() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j) {
                m[i][j] = Inf;
            } else {
                m[i][j] = 0;
            }
        }
    }
}

int main() {
    cin >> kase;
    while (kase--) {
        cin >> f >> n;
        for (int i = 1; i <= f; i++) {
            cin >> itnum[i];
        }

        initial();

        cin.ignore();
        while (getline(cin, in) && in != "") {
            stringstream ss(in);
            int a, b, c;
            ss >> a >> b >> c;
            m[a][b] = m[b][a] = c;
        }

        floy();

        int s_l[505];   //short length
        int max_s_l = 0;
        for (int i = 1; i <= n; i++) {
            s_l[i] = Inf;
            for (int j = 1; j <= f; j++) {
                s_l[i] = min(m[i][itnum[j]], s_l[i]);
            }
            max_s_l = max(s_l[i], max_s_l);
        }

        int ans = 1;
        for (int i = 1; i <= n; i++) {
            int n_l = 0;    //new length
            for (int j = 1; j <= n; j++) {
                int shorter = min(m[i][j], s_l[j]);
                n_l = max(shorter, n_l);
            }
            if (n_l < max_s_l) {
                max_s_l = n_l;
                ans = i;
            }
        }

        cout << ans << endl;
        if (kase) {
            cout << endl;
        }
    }

    return 0;
}