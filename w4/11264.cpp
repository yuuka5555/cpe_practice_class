#include <iostream>
#include <vector>
using namespace std;

int main() {
    int c;
    scanf("%d", &c);

    while (c--) {
        int n;
        scanf("%d", &n);

        vector<int> coinType;
        for (int i = 0; i < n; i++) {
            int in;
            scanf("%d", &in);
            coinType.push_back(in);
        }

        int sum = 1;
        int coin = 1;
        if (n > 1) {
            coin++;
        }

        for (int i = 1; i < n-1; i++) {
            if (sum + coinType[i] < coinType[i+1]) {
                sum += coinType[i];
                coin++;
            }           
        }

        printf("%d\n", coin);
    }

    return 0;
}