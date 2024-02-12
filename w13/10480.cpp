#include <bits/stdc++.h>
using namespace std;

int g[55][55];
int rg[55][55]; //residual graph
int parent[55];
int flow[55];
int n, m, p;

int bfs(int s, int t) {
    memset(parent, 0, sizeof(parent));
    memset(flow, 0, sizeof(flow));

    queue<int> b;
    b.push(s);
    parent[s] = s;
    flow[s] = 1e9;
    while (!b.empty()) {
        int cur = b.front();
        b.pop();

        for (int i = 1; i <= n; i++) {
            if (rg[cur][i] > 0 && !parent[i]) {
                parent[i] = cur;
                flow[i] = min(flow[cur], rg[cur][i]);
                if (i == t) {
                    return flow[i];
                }
                b.push(i);
            }
        }
    }

    return 0;
}

int main() {
    while (cin >> n >> m && (n || m)) {
        for (int i = 0; i <= 54; i++) {
            memset(g[i], 0, sizeof(g[i]));
            memset(rg[i], 0, sizeof(rg[i]));
        }

        for (int i = 1; i <= m; i++) {
            int u, v, c;
            cin >> u >> v >> c;
            g[u][v] = g[v][u] = rg[u][v] = rg[v][u] = c;
        }

        while ((p = bfs(1, 2)) != 0) {
            for (int from = parent[2], to = 2; from != to; from = parent[to = from]) {
                rg[from][to] -= p;
                rg[to][from] += p;
            }
        }

        for (int i = 1; i <= n; i++) {
            if (flow[i] > 0) {
                for (int j = 1; j <= n; j++) {
                    if (!flow[j] && g[i][j]) {
                        cout << i << " " << j << endl;
                    }
                }
            }
        }
        cout << endl;
    }

    return 0;
}