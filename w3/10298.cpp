#include <iostream>

using namespace std;

int nexts[1000000];

int main() {
    string s;
    while (cin >> s && s != ".") {
        int i = 0;
        int k = -1;
        nexts[0] = -1;

        //kmp
        while (i < s.length()) {
            if (k == -1 || s[i] == s[k]) {
                nexts[++i] = ++k;
            } else {
                while (k != -1 && s[i] != s[k]) {
                    k = nexts[k];
                }
            }
        }

        for (int i = 0; i <= s.length(); i++) {
            cout << nexts[i] << " ";
        }
        cout << endl;

        int repeat = s.length() - nexts[s.length()];

        if (s.length() % repeat == 0) {
            cout << s.length() / repeat << endl;
        } else {
            cout << 1 << endl;
        }
    }

    return 0;
}