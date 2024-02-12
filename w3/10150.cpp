//doublet

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <string.h>
using namespace std;

char word[25145][17];

bool isDoublet(int a, int b, int len) {
    int i, diffNum;
    for (i = 0, diffNum = 0; i < len; i++) {
        diffNum += word[a][i] != word[b][i];

        if (diffNum > 1) {
            return false;
        }
    }

    return diffNum == 1;
}

int main() {
    int wordNum = 0;
    vector<int> lengthRecord[17];
    map<string, int> wordIndex[17];    //[length][word name] = index

    while (gets(word[wordNum]) && word[wordNum][0] != '\0') {
        lengthRecord[strlen(word[wordNum])].push_back(wordNum);
        wordIndex[strlen(word[wordNum])][word[wordNum]] = wordNum;
        wordNum++;
    }

    //build graph
    vector<int> interaction[25145];
    for (int i = 1; i < 17; i++) {
        for (int j = 0; j < lengthRecord[i].size(); j++) {
            for (int k = 1; k < lengthRecord[i].size(); k++) {
                if (isDoublet(lengthRecord[i][j], lengthRecord[i][k], i)) {
                    interaction[lengthRecord[i][j]].push_back(lengthRecord[i][k]);
                    interaction[lengthRecord[i][k]].push_back(lengthRecord[i][j]);
                }
            }
        }
    }

    int pre[25145];
    char start[20], end[20];
    int first = 0;
    while (scanf("%s %s", &start, &end) == 2) {
        if (first) {
            printf("\n");
        } else {
            first = 1;
        }

        if (strlen(start) != strlen(end)) {
            printf("No solution.\n");
            continue;
        }

        int sIndex = wordIndex[strlen(start)][start];
        int eIndex = wordIndex[strlen(end)][end];

        //bfs
        queue<int> bfs;
        bfs.push(eIndex);

        char visit[25145] = {};
        int pre[25145];   //record the last word in bfs

        while (!bfs.empty()) {
            int p = bfs.front();
            bfs.pop();

            for (auto i : interaction[p]) {
                if (!visit[i]) {
                    bfs.push(i);
                    pre[i] = p;
                    visit[i] = 1;
                }
            }

            if (visit[sIndex] == 1) {
                break;
            }
        }
        
        pre[eIndex] = -1;
        
        if (!visit[sIndex]) {
            printf("No solution.\n");
        } else {
            while (sIndex >= 0) {
                printf("%s\n", word[sIndex]);
                sIndex = pre[sIndex];
            }
        }
    }

    return 0;
}