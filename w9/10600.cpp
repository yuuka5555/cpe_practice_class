#include <bits/stdc++.h>
#define inf 1000000000
using namespace std;

int t, m, n, a, b, c;
vector<int> p;
vector<bool> valid, used;
vector<pair<int, pair<int, int>>> edgeMap;

int findSet(int i) {
    if (p[i] == -1) {
        return i;
    } else {
        return p[i] = findSet(p[i]);
    }
}

int minSpanningTree(bool flag) {
    p.assign(n+1, -1);
    int edgeCount = 0;
    int edgeCost = 0;
    int x, y, z;
    for (int i = 0; i < m; i++) {
        if (valid[i]) {
            x = edgeMap[i].second.first;
            y = edgeMap[i].second.second;
            z = edgeMap[i].first;
            int xHead = findSet(x);
            int yHead = findSet(y);
            
            if (xHead != yHead) {
                if (flag) {
                    used[i] = true;
                }
                p[xHead] = yHead;
                edgeCount++;
                edgeCost += z;
            }
        }
    }
    if (edgeCount == n-1) {
        return edgeCost;
    } else {
        return inf;
    }
}

int secMinSpanningTree() {
    int tmp = inf, temp;
    for (int i = 0; i < m; i++) {
        if (used[i]) {
            valid[i] = false;
            temp = minSpanningTree(false);
            if (temp < tmp) {
                tmp = temp;
            }
            valid[i] = true;
        }
    }

    return tmp;
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> m;
        edgeMap.clear();
        valid.assign(m, true);
        used.assign(m, false);

        for (int i = 0; i < m; i++) {
            cin >> a >> b >> c;
            edgeMap.push_back(make_pair(c, make_pair(a, b)));
        }
        sort(edgeMap.begin(), edgeMap.end());

        int minCost = minSpanningTree(true);
        int secCost = secMinSpanningTree();
        cout << minCost << " " << secCost << endl;
    }

    return 0;
}