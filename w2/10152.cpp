//turtle stack

#include <iostream>
using namespace std;

int main() {
    int caseNum;
    cin >> caseNum;

    while (caseNum--) {
        int turtleNum;
        cin >> turtleNum;

        string original[turtleNum];
        string desired[turtleNum];

        cin.ignore();

        for (int i = 0; i < turtleNum; i++) {
            getline(cin, original[i]);
        }

        for (int i = 0; i < turtleNum; i++) {
            getline(cin, desired[i]);
        }

        int j = turtleNum - 1;
        for (int i = turtleNum - 1; i >= 0; i--) {
            if (original[i] == desired[j]) {
                j--;
            }
        }

        for (int i = j; i >= 0; i--){
            cout << desired[i] << endl;
        }

        printf("\n");
    }

    return 0;
}