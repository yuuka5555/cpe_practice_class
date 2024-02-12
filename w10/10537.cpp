#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, c = 1, s, e;
ll num;
ll inf = 1e16;
ll d[55];
bool vis[55];
bool g[55][55];
int p[55];

int char2int(char ch) {
    if (ch >= 'a') {
        return ch - 'a' + 26;
    } else {
        return ch - 'A';
    }
}

char int2char(int in) {
    if (in >= 26) {
        return in - 26 + 'a';
    } else {
        return in + 'A';
    }
}

ll calc(ll dk, int k) {
    if (k < 26) {
        return ceil(dk * 20 / 19.0);
    } else {
        return dk + 1;
    }
}

void dijkstra() {
    fill(d, d + 55, inf);
    d[e] = num; 
    
    for (int i = 0; i < 55; i++) {
        int k = -1;
        ll mind = inf;

        for (int j = 0; j < 55; j++) {
            if (!vis[j] && mind > d[j]) {
                mind = d[j];
                k = j;
            }
        }

        if (k == -1) break;
        vis[k] = true;
        ll dist = calc(d[k], k);

        for (int l = 0; l < 55; l++) {
            if (!vis[l] && g[k][l]) {
                if (d[l] > dist) {
                    d[l] = dist;
                    p[l] = k;
                } else if (dist == d[l] && k < p[l]) {
                    p[l] = k;
                }
            }
        }
    }
}

void print_ans(int i) {
    if (i == e) {
        cout << int2char(i) << endl;
        return;
    } else {
        cout << int2char(i) << "-";
        print_ans(p[i]);
    }
}

int main() {
    while (cin >> n) {
        if (n == -1) break;

        memset(g, false, sizeof(g));
        memset(p, -1, sizeof(p));
        memset(vis, false, sizeof(vis));

        for (int i = 0; i < n; i++) {
            char c1, c2;
            cin >> c1 >> c2;
            int i1 = char2int(c1);
            int i2 = char2int(c2);
            g[i1][i2] = g[i2][i1] = true;
        }

        char sta, des;
        cin >> num >> sta >> des;

        s = char2int(sta);
        e = char2int(des);
        dijkstra();

        cout << "Case " << c++ << ":" <<endl;
        cout << d[s] << endl;
        print_ans(s);
    }

    return 0;
}