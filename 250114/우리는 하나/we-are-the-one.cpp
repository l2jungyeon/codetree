#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

const int dx[] = { 0,0,1,-1 };
const int dy[] = { 1,-1,0,0 };

int solve(int xx, int yy, int u, int d, const vector<vector<int>> & map,
	vector<vector<bool>>& visited) {
	int n = map.size();
	int total = 0;

	queue<pair<int, int>> q;
	q.push({ xx,yy });

	while (!q.empty()) {
		int curX = q.front().first;
		int curY = q.front().second;
		int curh = map[curX][curY];
		q.pop();

		if (visited[curX][curY]) continue;
		visited[curX][curY] = true;
		total++;

		for (int i = 0; i < 4; i++) {
			int x = curX + dx[i];
			int y = curY + dy[i];
			if (x >= 0 && x < n && y >= 0 && y < n
				&& !visited[x][y]
				&& abs(curh - map[x][y]) >= u
				&& abs(curh - map[x][y]) <= d) {
				q.push({ x,y });
			}
		}
	}

	return total;
}

bool compare(int a, int b) {
	return a > b;
}

int main() {
	int n, k, u, d;
	cin >> n >> k >> u >> d;
	//k개의 도시를 골라서 갈수있는 서로 다른 도시의 수

	vector<vector<int>> map(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	vector<int> maxVec;
	vector<vector<bool>> visited(n, vector<bool>(n, false));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int m = solve(i, j, u, d, map, visited);
			maxVec.push_back(m);
		}
	}

	int max = 0;
	sort(maxVec.begin(), maxVec.end(), compare);
	for (int i = 0; i < k; i++) {
		max += maxVec[i];
	}
	cout << max;
}