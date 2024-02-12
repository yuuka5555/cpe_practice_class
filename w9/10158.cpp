#include <bits/stdc++.h>

using namespace std;

int people, c, x, y, a1, a2, b1, b2;
int all[20001];

int find(int i) {
    if (i != all[i]) {
        return find(all[i]);
    } else {
        return i;
    }
}

int main() {
    while (cin >> people) {
        for (int i = 0; i < 2*people; i++) {
            all[i] = i;
        }

        while (cin >> c >> x >> y) {
            if (c == 0) break;
            a1 = find(x);
            a2 = find(x + people);
            b1 = find(y);
            b2 = find(y + people);
            
            if (c == 1) {
                if (a1 == b2) {
                    cout << -1 << endl;
                } else {
                    all[a1] = b1;
                    all[a2] = b2;
                }
            } else if (c == 2) {
                if (a1 == b1) {
                    cout << -1 << endl;
                } else {
                    all[a1] = b2;
                    all[b1] = a2;
                }
            } else if (c == 3) {
                if (a1 == b1) {
                    cout << 1 << endl;
                } else {
                    cout << 0 << endl;
                }
            } else if (c == 4) {
                if (a1 == b2) {
                    cout << 1 << endl;
                } else {
                    cout << 0 << endl;
                }
            }
        }
    }

    return 0;
}