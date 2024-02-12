//shoemaker

#include <iostream>
#include <algorithm>
using namespace std;

typedef struct {
    int idx;
    double avg;
} eachJob;

bool compare(eachJob a, eachJob b) {
    if (a.avg == b.avg) {
        return a.idx < b.idx;
    }
    return a.avg > b.avg;
}

int main() {
    int caseNum;
    cin >> caseNum;

    while (caseNum--) {      
        int job;
        cin >> job;

        eachJob all[job];
        for (int i = 0; i < job; i++) {
            double day, fine;
            cin >> day >> fine;

            all[i].idx = i+1;
            all[i].avg = fine / day; // 上課聽別人報告的(雖然我還沒想通
        }

        sort(all, all + job, compare);

        for (int i = 0; i < job; i++) {
            if (i < job-1) {
                cout << all[i].idx << " ";
            } else {
                cout << all[i].idx << endl;
            }
        }

        if (caseNum) {
            printf("\n");
        }
    }

    return 0;
}