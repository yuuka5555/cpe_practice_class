#include <iostream>
#include <cmath>
using namespace std;

typedef unsigned int uint;

int main() {
    uint n;

    while (scanf("%u",&n)){
        if (!n) break;

        uint a = sqrt(n);
        if (a * a == n) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }
    
    return 0;
}