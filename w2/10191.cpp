//schedule

#include <iostream>
#include <algorithm>
using namespace std;

typedef struct {
    int start;
    int end;
} schedule;

bool compare(schedule x, schedule y) {
    if (x.start != y.start) {
        return x.start < y.start;
    }
    return x.end < y.end;
}

int main() {
    int scheduleNum;
    int day = 0;
    while (cin >> scheduleNum) {
        schedule allTime[102];
        
        for (int i = 0; i < scheduleNum; i++) {
            int startH, startM, endH, endM;
            string scheduleName;
            scanf("%d:%d", &startH, &startM);
            scanf("%d:%d", &endH, &endM);
            getline(cin, scheduleName);

            allTime[i].start = startH*60 + startM;
            allTime[i].end = endH*60 + endM;
        }

        allTime[scheduleNum].start = 600;
        allTime[scheduleNum].end = 600;
        allTime[scheduleNum+1].start = 1080;
        allTime[scheduleNum+1].end = 1080;

        sort(allTime, allTime + scheduleNum + 2, compare);

        int longest = 0;
        int longestStart;
        for (int i = 1; i < scheduleNum+2; i++) {
            if (allTime[i].start - allTime[i - 1].end > longest) {
                longest = allTime[i].start - allTime[i - 1].end;
                longestStart = allTime[i - 1].end;
            }
        }

        printf("Day #%d: the longest nap starts at ", ++day);
        printf("%02d:%02d and will last for ", longestStart/60, longestStart%60);
        if(longest >= 60) {
            printf("%d hours and ", longest/60);
        }
        printf("%d minutes.\n", longest%60);
    }


    return 0;
}