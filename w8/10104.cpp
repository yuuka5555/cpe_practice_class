#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b, int &x, int &y) {
    if (a % b == 0) {
        x = 0;
        y = 1;
        return b;
    }

    if (b % a == 0) {
        x = 1;
        y = 0;
        return a;
    }

    if (a >= b) {
        int xx, yy;
        int value = gcd(a+b*(-a/b), b, xx, yy);
        x = xx;
        y = yy + xx*(-a/b);
        return value;
    } else {
        int xx, yy;
        int value = gcd(a, b+a*(-b/a), xx, yy);
        x = xx + yy*(-b/a);
        y = yy;
        return value;
    }
}

int main() {
    int a, b;
    while (cin >> a >> b) {
        int x, y;
        int value = gcd(a, b, x, y);
        printf("%d %d %d\n", x, y, value);
    }

    return 0;
}