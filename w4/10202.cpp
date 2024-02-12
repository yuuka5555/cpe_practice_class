//pairsum
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        int cn2 = n * (n-1) / 2;
        vector<int> sum;
        for (int i = 0; i < cn2; i++) {
            int s;
            scanf("%d", &s);
            sum.push_back(s);
        }

        sort(sum.begin(), sum.end());
        
        int adjust = 0;
        if (sum[0] < 0) {
            adjust = (-2) * sum[0];
        }

        if (adjust != 0) {
            for (int i = 0; i < sum.size(); i++) {
                sum[i] += adjust;
            }
        }

        int biggestSol0 = sum[0] / 2;
        bool found = false;
        for (int i = 0; i <= biggestSol0; i++) {
            vector<int> sol;
            sol.push_back(i);

            vector<int> checkSum = sum;
            while (!checkSum.empty()) {
                int next = checkSum[0] - sol[0];
                for (int j = 0; j < sol.size(); j++) {
                    vector<int> :: iterator it;
                    it = find(checkSum.begin(), checkSum.end(), next + sol[j]);

                    if (it != checkSum.end()) {
                        checkSum.erase(it);
                    } else {
                        checkSum.clear();
                        sol.clear();
                        break;
                    }
                }

                if (!sol.empty()) {
                    sol.push_back(next);
                }
            }

            if (!sol.empty()) {
                for (int j = 0; j < n; j++) {
                    if (j < n-1) {
                        printf("%d ", sol[j] - adjust/2);
                    } else {
                        printf("%d", sol[j] - adjust/2);
                    }
                }
                printf("\n");
                found = true;
                break;
            }
        }

        if (!found) {
            printf("Impossible\n");
        }
    }

    return 0;
}