//ones
#include <iostream>
using namespace std;

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        if (!n) {
            printf("0\n");
            continue;
        }
        int i = 1;
        int r = 1 % n;
        while (r) {
            r *= 10;
            r++;
            r = r % n;
            i++;
        }

        printf("%d\n", i);
    }

    return 0;
}