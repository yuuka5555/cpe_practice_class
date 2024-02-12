#include <bits/stdc++.h>
using namespace std;

int n = 0, ans = 0;
string s;
vector<int> graph[25001];
int paths[25001] = {0};
unordered_map<string, int> word_ind;
string ind_word[25001];

void changing(string cur, int l, int from) {
    for (int i = 0; i < l; i++) {
        for (char c = cur[i] + 1; c <= 'z'; c++) {
            string tmp = cur;
            tmp[i] = c;
            if (word_ind.count(tmp) > 0) {
                int dest = word_ind[tmp];
                graph[from].push_back(dest);
            }
        }
    }
}

void deleting(string cur, int l, int from) {
    for (int i = 0; i < l; i++) {
        string tmp;
        tmp.reserve(l-1);
        for (int j = 0; j < l; j++) {
            if (i != j) {
                tmp.push_back(cur[j]);
            }
        }
        if (word_ind.count(tmp) > 0) {
            int dest = word_ind[tmp];
            if (from < dest) graph[from].push_back(dest);
        }
    }
}

void inserting(string cur, int l, int from) {
    for (int i = 0; i <= l; i++) {
        for (char c = 'a'; c <= 'z'; c++) {
            string tmp;
            tmp.reserve(l+1);
            if (i == l) {
                tmp = cur;
                tmp.push_back(c);
            } else {
                for (int k = 0; k < l; k++) {
                    if (k == i) {
                        tmp.push_back(c);
                    }
                    tmp.push_back(cur[k]);
                }
            }

            if (word_ind.count(tmp) > 0) {
                int dest = word_ind[tmp];
                if (from < dest) graph[from].push_back(dest);
            }
        }
    }
}

int find_path(int i) {
    if (paths[i] > 0) return paths[i];

    int max_p = 0;
    for (int j : graph[i]) {
        int result = find_path(j);
        if (result > max_p) max_p = result;
    }

    paths[i] = max_p + 1;
    return paths[i];
}

int main() {
    while (cin >> s) {
        ind_word[n] = s;
        word_ind[s] = n;
        n++;
    }

    for (int i = 0; i < n; i++) {
        string cur = ind_word[i];
        int len = cur.length();
        changing(cur, len, i);
        deleting(cur, len, i);
        inserting(cur, len, i);
    }

    for (int i = 0; i < n; i++) {
        ans = max(ans, find_path(i));
    }

    cout << ans << endl;

    return 0;
}