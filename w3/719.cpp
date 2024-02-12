#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    while (n--) {
        string nl;
        cin >> nl;
        
        int len = nl.length();
        int bead = 0;
        string target = nl;
        nl += nl;

        for (int i = 1; i < len; i++) {
            if (nl.substr(i, len) < target) {
                target = nl.substr(i, len);
                bead = i;
            }
        }
        
        bead++;

        cout << bead << endl;

    }

    return 0;
}