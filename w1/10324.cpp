//zeros and ones
#include <bits/stdc++.h>
using namespace std;

int main() {
    string input;
    int count = 1;

    while (cin >> input) {
        cout << "Case " << count << ":" << endl;
        count++;

        int sum[input.length()];
        for (int i = 0; i < input.length(); i++) {
            if (i == 0) {
                sum[i] = input[i] - '0';
            } else {
                sum[i] = sum[i - 1] + (input[i] - '0');
            }
        }

        int queriesNum;
        cin >> queriesNum;
        for (int i = 0; i < queriesNum; i++) {
            int posSmall, posBig;
            cin >> posSmall >> posBig;
            if (posBig < posSmall) {
                int tmp = posBig;
                posBig = posSmall;
                posSmall = tmp;
            }


            int total = sum[posBig] - sum[(posSmall - 1) < 0 ? 0 : posSmall - 1];
            if (total == 0 || total == posBig - posSmall + 1) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
    

    return 0;
}
