//erdos number

#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int main() {
    int scenario = 1;
    int caseNum;
    cin >> caseNum;

    for (int l = 0; l < caseNum; l++) {
        int p, n;
        cin >> p >> n;

        map<string, int> authorIndex;
        bool interaction[5000][5000];
        int index = 1;

        memset(interaction, false, sizeof interaction);

        getchar();

        for (int i = 0; i < p; i++) {
            char paper[100000];
            
            gets(paper);
            vector<string> authors;

            int cur = 0;
            string name = "";
            while (true) {
                name += paper[cur];
            
                if (paper[cur] == '.' && paper[cur+1] == ':') {
                    authors.push_back(name);
                    if (!authorIndex[name]) {
                        authorIndex[name] = index;
                        index++;
                    }
                    break;
                } else if (paper[cur] == '.' && paper[cur+1] == ',') {
                    authors.push_back(name);
                    if (!authorIndex[name]) {
                        authorIndex[name] = index;
                        index++;
                    }
                    name = "";
                    cur += 3;
                    continue;
                }

                cur++;
            }

            for (int j = 0; j < authors.size(); j++) {
                for (int k = j+1; k < authors.size(); k++) {
                    interaction[authorIndex[authors[j]]][authorIndex[authors[k]]] = interaction[authorIndex[authors[k]]][authorIndex[authors[j]]] = true;
                }
            }
        }

        vector<string> search;
        for (int i = 0; i < n; i++) {
            char searchName[50];
            gets(searchName);
            search.push_back(searchName);

            if (!authorIndex[searchName]) {
                authorIndex[searchName] = index;
                index++;
            }
        }

        queue<pair<int, int>> bfs;

        for (auto s : authorIndex) {
            if (s.first == "Erdos, P.") {
                bfs.push(make_pair(authorIndex[s.first], 0));
                break;
            }
        }

        bool visit[index+1];
        memset(visit, false, sizeof visit);

        int erdoNum[index+1];
        memset(erdoNum, -1, sizeof erdoNum);

        while (!bfs.empty()) {
            pair<int, int> pop = bfs.front();
            bfs.pop();
            erdoNum[pop.first] = pop.second;

            for (int i = 1; i <= index; i++) {
                if (interaction[pop.first][i] && !visit[i]) {
                    bfs.push(make_pair(i, pop.second + 1));
                    visit[i] = true;
                }
            }
        }

        printf("Scenario %d\n", scenario);
        for (int i = 0; i < search.size(); i++) {
            if (erdoNum[authorIndex[search[i]]] == -1) {
                printf("%s infinity\n", search[i].c_str());
            } else {
                printf("%s %d\n", search[i].c_str(), erdoNum[authorIndex[search[i]]]);
            }
        }

        scenario++;
    }

    return 0;
}