#include <bits/stdc++.h>

using namespace std;

int n, m, trav;
int c = 1;
int low[110];
int dfn[110];
string loc[110];
bool graph[110][110];
bool vis[110];
map<string, int> ind;
vector<string> ans;

void dfs(int pa, int cur) {
    int child = 0;
    int next;
    bool flag = false;
    dfn[cur] = trav;
    low[cur] = trav;
    vis[cur] = true;
    trav++;

    for (int i = 0; i < n; i++) {
        next = i;
        if (graph[cur][next]) {
            if (!vis[next]) {
                child++;
                dfs(cur, next);

                if (low[cur] > low[next]) {
                    low[cur] = low[next];
                }

                if (low[next] >= dfn[cur]) {
                    flag = true;
                }
            } else if (pa != next) {
                if (dfn[next] < low[cur]) {
                    low[cur] = dfn[next];
                }
            }
        }
    }

    if (flag && (child > 1 || pa != -1)) {
        ans.push_back(loc[cur]);
    }

    return;
}

int main() {
    while (cin >> n && n) {
        memset(graph, false, sizeof(graph));
        memset(vis, false, sizeof(vis));
        memset(low, 0, sizeof(low));
        memset(dfn, 0, sizeof(dfn));
        
        cin.ignore();
        for (int i = 0; i < n; i++) {
            cin >> loc[i];
            ind[loc[i]] = i;
        }

        scanf("%d", &m);
        cin.ignore();
        for (int i = 0; i < m; i++) {
            string a, b;
            cin >> a >> b;
            graph[ind[a]][ind[b]] = graph[ind[b]][ind[a]] = true;
        }

        trav = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(-1, i);
            }
        }

        if (c != 1) {
            printf("\n");
        }

        printf("City map #%d: %d camera(s) found\n",c++,ans.size());
        sort(ans.begin(), ans.end());
        for (auto a : ans) {
            printf("%s\n", a.c_str());
        }

        ind.clear();
        ans.clear();
    }

    return 0;
}