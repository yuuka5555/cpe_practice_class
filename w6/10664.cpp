#include <bits/stdc++.h>
using namespace std;

vector<int> weight;
bool dp[4205];
int sum, n;
string tmp;

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        sum = 0;
        memset(dp, false, sizeof(dp));
        dp[0] = true;
        weight.clear();
        
        getline(cin, tmp);
        stringstream ss(tmp);
        while (ss >> n) {
            weight.push_back(n);
            sum += n;
        }

        if (sum % 2 != 0) {
            cout << "NO" << endl;
            continue;
        } else {
            sum = sum >> 1;
        }

        for (auto v : weight) {
            for (int j = sum - v; j >= 0; j--) {
                if (dp[j] && !dp[j+v]) {
                    dp[j+v] = true;
                }
            }
        }

        if (dp[sum]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}