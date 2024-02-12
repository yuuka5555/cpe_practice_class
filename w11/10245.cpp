// divide and conquer
#include <bits/stdc++.h>
using namespace std;

struct point {
    double x;
    double y;
};

int n;
point all[10005];

bool cmp(point a, point b) {
    return a.x < b.x;
}

double dist(point a, point b) {
    return (double)sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

double combine(int left, int mid, int right, double min_left, double min_right) {
    double d = (min_left < min_right ? min_left : min_right);
    double mid_x = (double)(all[mid].x + all[mid+1].x) / 2.0;
    double min_dist = d;

    for (int i = mid+1; i <= right && all[i].x < mid_x + d; i++) {
        for (int j = mid; j >= left && all[j].x > mid_x - d; j--) {
            double tmp = dist(all[i], all[j]);
            if (tmp < min_dist) {
                min_dist = tmp;
            }
        }
    }
    
    return min_dist;
}

double divide(int left, int right) {
    if (left >= right) {
        return 99999;
    }

    int mid = (left + right) / 2;
    double min_left = divide(left, mid);
    double min_right = divide(mid+1, right);
    return combine(left, mid, right, min_left, min_right);
}

int main() {
    while (cin >> n && n) {
        for (int i = 0; i < n; i++) {
            cin >> all[i].x >> all[i].y;
        }

        sort(all, all+n, cmp);

        double dist = divide(0, n-1);
        if (dist >= 10000.0) {
            cout << "INFINITY" << endl;
        } else {
            printf("%.4lf\n", dist);
        }
    }

    return 0;
}