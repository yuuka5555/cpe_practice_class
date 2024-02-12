//cdvii

#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

typedef struct {
    string license;
    int date, hour, minute, miles;
    int time;
    bool isExit;
} record;

bool compare(record x, record y) {
    return x.time < y.time;
}

int main() {
    int caseNum;
    scanf("%d\n\n", &caseNum);

    while (caseNum--) {
        int allFare[24];

        for (int j = 0; j < 24; j++) {
            cin >> allFare[j];
        }

        cin.ignore();

        map<string, vector<record>> allRecord;

        string photo;
        while (getline(cin, photo) && !photo.empty()) {
            string licenseName;
            int month, date, hour, minute, miles;
            string status;
            char ignore;

            record eachPhoto;

            istringstream iss(photo);
            iss >> eachPhoto.license >> month >> ignore >> date >> ignore >> hour >> ignore >> minute >> status >> eachPhoto.miles;

            eachPhoto.hour = hour;
            eachPhoto.time = date*24*60 + hour*60 + minute;
            eachPhoto.isExit = status == "exit";

            allRecord[eachPhoto.license].push_back(eachPhoto);
        }

        for (auto s : allRecord) {
            sort(s.second.begin(), s.second.end(), compare);

            double cost = 200;

            for (int j = 0; j < s.second.size(); j++) {
                if (!s.second[j].isExit && s.second[j+1].isExit && j < s.second.size() - 1) {
                    cost += abs(s.second[j+1].miles - s.second[j].miles)*allFare[s.second[j].hour] + 100;
                }
            }

            if (cost != 200) {
                printf("%s $%.2f\n", s.first.c_str(), cost/100.0);
            }
        }
        if (caseNum) {
            printf("\n");
        }
    }
    
    return 0;
}