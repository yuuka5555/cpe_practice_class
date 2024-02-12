#include <bits/stdc++.h>

using namespace std;

int main() {
    char s[100001];
    char q[1001];
    int n;
    cin >> n;

    while (n--) {
        cin >> s;
        
        int test;
        cin >> test;
        while (test--) {
            cin >> q;

            cout << (strstr(s, q)? "y" : "n") << endl; // This is so cool
        }
    }

    return 0;
}