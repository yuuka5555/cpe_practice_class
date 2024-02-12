//trip
#include <iostream>

using namespace std;

int main() {
    int n;

    while(cin >> n) {
        if (!n) {
            break;
        }
        
        int totalCost[n];
        double sumCost = 0;
        for (int i = 0; i < n; i++) {
            int dollars;
            int cents;
            scanf("%d.%d", &dollars, &cents);
            totalCost[i] = dollars * 100 + cents;
            sumCost += totalCost[i];
        }

        double avgCost = sumCost/n;
        double more = 0;
        double less = 0;

        for (int i = 0; i < n; i++) {
            double diff = totalCost[i] - avgCost;
            
            if (diff > 0) {
                more += (int)diff/100.0;
            } else {
                less -= (int)diff/100.0;
            }
        }

        printf("$%.2f\n", more > less ? more : less);
    }
    
    return 0;
}