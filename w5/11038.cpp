// how many zero

#include <iostream>
using namespace std;

typedef long long int lli;

lli sum(lli n) {
    lli N = n;
    lli sum = 0;
    int i = 1;
    int mid;

    while (N >= 10) {
        mid = N % 10;
        N /= 10;

        if (mid) {
            sum += N * i;
        } else {
            sum += (N-1) * i + n % (i*10) + 1;
        }
        i *= 10;
    }
    return sum;
}

int main() {
    lli m, n;
    while (scanf("%lld %lld", &m, &n)) {
        if (m < 0) {
            break;
        }

        lli ans = sum(n) - sum(m-1);
        if (m == 0) {
            ans++;
        }
        printf("%lld\n", ans);
    }

    return 0;
}