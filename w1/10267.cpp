#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;
typedef char color;

char graph[251][251];
int m, n, x, y, x1, x2, y1, y2;
color c;
char instruction;
bool flag = false;

void dfs(int x,int y,color c,color nowcolor){
	if(x<1 || y<1 || x>m || y>n || graph[y][x] != nowcolor) return;
	graph[y][x] = c;
	dfs(x+1, y, c, nowcolor);
	dfs(x-1, y, c, nowcolor);
	dfs(x, y+1, c, nowcolor);
	dfs(x, y-1, c, nowcolor);
}
void I() {
	memset(graph, 'O', sizeof(graph));
}
void C() {
	memset(graph, 'O', sizeof(graph));
}
void L() {
	graph[y][x] = c;
}
void V() {
	if (y1 > y2) swap(y1, y2);
	for (int col = y1; col <= y2; col++)
		graph[col][x] = c;
}
void H() {
	if (x1 > x2) swap(x1, x2);
	for (int row = x1; row <= x2; row++) {
		graph[y][row] = c;
	}
}
void K() {
	if (x1 > x2) swap(x1, x2);
	if (y1 > y2) swap(y1, y2);
	for (int row = x1; row <= x2; row++) {
		for (int col = y1; col <= y2; col++) {
			graph[col][row] = c;
		}
	}
}
void F() {
	if (graph[y][x] != c) dfs(x, y, c, graph[y][x]);
}

void S(string Name) {
	cout << Name << endl;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cout << graph[i][j];
		}
		cout << endl;
	}
}

int main() {	
	while (!flag) {
		cin >> instruction;
		if (instruction == 'I') {
			cin >> m >> n;
			I();
		} else if (instruction == 'C') {
			C();
		} else if (instruction == 'L') {
			cin >> x >> y >> c;
			L();
		} else if (instruction == 'V') {
			cin >> x >> y1 >> y2 >> c;
			V();
		} else if (instruction == 'H') {
			cin >> x1 >> x2 >> y >> c;
			H();
		} else if (instruction == 'K') {
			cin >> x1 >> y1 >> x2 >> y2 >> c;
			K();
		} else if (instruction == 'F') {
			cin >> x >> y >> c;
			F();
		} else if (instruction == 'S') {
			string name;
			cin >> name;
			S(name);
		} else if (instruction == 'X') {
			flag = true;
		} else {
			string trash;
			getline(cin, trash);
		}
	}

	return 0;
}