#include <bits/stdc++.h>
using namespace std;

typedef struct {
    double x, y;
}point;

int n, m;
point p[101];
point ch[101];

double cross(point o, point p1, point p2) {
    return (p1.x-o.x)*(p2.y-o.y) - (p1.y-o.y)*(p2.x-o.x);
}

bool cmp(point a, point b){
	if(a.y == b.y)  return a.x < b.x;
	return a.y < b.y;
}

bool right(point o, point p1, point p2) {
	if(cross(o, p1, p2) <= 0) return true;
	return false;
}

bool cmp_angle(point a, point b) {
    if (right(p[0], a, b)) return false;
    return true;
}

void graham() {
    sort(p, p+n, cmp);
    sort(p+1, p+n, cmp_angle);

    p[n] = p[0];

    m = 0;
    for (int i = 0; i <= n; i++) {
        while (m >= 2 && right(ch[m-2], ch[m-1], p[i])) {
            m--;
        }
        ch[m++] = p[i];
    }
    m--;
}

double cal_area(point p0, point p1, point p2){
    double area = cross(p0, p1, p2);
    return area / 2 ;
}

int main() {
    while (cin >> n && n >= 3) {
        for (int i = 0; i < n; i++) {
            point input;
            cin >> input.x >> input.y;
            p[i] = input;
        }

        graham();

        double sum_x , sum_y , sum_area , area;
	    sum_x = sum_y = sum_area = area = 0;
        for(int i=2; i < m; i++){
            area = cal_area(ch[0],ch[i-1],ch[i]) ;
            sum_area += area ;
            sum_x += (ch[0].x + ch[i-1].x + ch[i].x) * area ;
            sum_y += (ch[0].y + ch[i-1].y + ch[i].y) * area ;
        }

	    printf ("%.3lf %.3lf\n", sum_x/sum_area/3, sum_y/sum_area/3);
    }

    return 0;
}