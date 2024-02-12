#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct point {
    int x, y;
};

int n;
double r, max_covering_r;
point all[101];

double distance(point a, point b) {
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return sqrt((double)(dx*dx + dy*dy));
}

int distance2(point a, point b) {
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return (dx*dx + dy*dy);
}

double good_circle_r(int i, int j, int k) {
    int a2 = distance2(all[i], all[j]);
    int b2 = distance2(all[j], all[k]);
    int c2 = distance2(all[k], all[i]);
    if (a2 > b2 + c2 || b2 > a2 + c2 || c2 > a2 + b2) return 0.0;

    double a = sqrt((double)a2);
    double b = sqrt((double)b2);
    double c = sqrt((double)c2);
    double p = (a+b+c)/2.0;
    double area = sqrt(p*(p-a)*(p-b)*(p-c));
    return a*b*c/(4.0*area);
}

int main() {
    while (cin >> n && n) {
        for (int i = 0; i < n; i++) {
            cin >> all[i].x >> all[i].y;
        }

        cin >> r;

        max_covering_r = 0.0;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                double d = distance(all[i], all[j]) * 0.5;
                if (d > max_covering_r) max_covering_r = d;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                for (int k = j+1; k < n; k++) {
                    double rtmp = good_circle_r(i, j, k);
                    if (rtmp > max_covering_r) max_covering_r = rtmp;
                }
            }
        }

        if (r >= max_covering_r) cout << "The polygon can be packed in the circle." << endl;
        else cout << "There is no way of packing that polygon." << endl;
    }

    return 0;
}