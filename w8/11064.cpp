#include <bits/stdc++.h>
using namespace std;

int fac[32], num[32];
int prim[150000];
int used[150000];

int main() {
    memset(used, 0, sizeof(used));
    int save = 0;
    for (int i = 2; i < 150000; i++) {
        if (!used[i]) {
            prim[save++] = i;
            for (int j = 2*i; j < 150000; j += i) {
                used[j] = 1;
            }
        }
    }

    int n;
    while (cin >> n && n) {
        int count = 0, base = 0, m = n;
        while (n > 1 && base < save) {
            if (n % prim[base] == 0) {
                fac[count] = prim[base];
                num[count] = 0;
                while (n % prim[base] == 0) {
                    n /= prim[base];
                    num[count]++;
                }
                count++;
            }
            base++;
        }

        if (n > 1) {
            fac[count] = n;
            num[count] = 1;
            count++;
        }

        long long ans = m;
        for (int i = 0; i < count; i++) {
            ans = ans / fac[i] * (fac[i]-1);
        }

        int s = 1;
        for (int i = 0; i < count; i++) {
            s = s*(num[i]+1);
        }

        cout << m - ans - s + 1 << endl;
    }

    return 0;
}