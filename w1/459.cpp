#include <bits/stdc++.h>
using namespace std;

bool graph[26][26];
bool vis[26];
int l;

bool dfs(int num) {
    if (vis[num]) {
        return false;
    } else {
        vis[num] = true;
        for (int j = 0; j < l; j++) {
            if (graph[num][j]) {
                dfs(j);
            }
        }
        return true;
    }
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        memset(graph, false, sizeof(graph));
        memset(vis, false, sizeof(vis));

        char largest;
        cin >> largest;

        l = largest - 'A' + 1;

        cin.ignore();

        string in;
        while (getline(cin, in) && in != "") {
            graph[in[0] - 'A'][in[1] - 'A'] = true;
            graph[in[1] - 'A'][in[0] - 'A'] = true;
        }

        int c = 0;
        for (int i = 0; i < l; i++) {
            if (dfs(i)) {
                c++;
            }
        }

        cout << c << endl;
        if (n != 0) {
            cout << endl;
        }
    }

    return 0;
}