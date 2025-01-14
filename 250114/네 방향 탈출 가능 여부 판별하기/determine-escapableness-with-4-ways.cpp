#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int dx[] = { 0,0,1,-1 };
const int dy[] = { 1,-1,0,0 };

bool solve(vector<vector<int>> graph) {
	int n = graph.size();
	int m = graph[0].size();

	vector<vector<bool>> visited(n, vector<bool>(m, false));

	queue<pair<int,int>> q;
	if (graph[0][0] == 1) {
		q.push({ 0,0 });
	}

	while (!q.empty()) {
		int curX = q.front().first;
		int curY = q.front().second;

		q.pop();

		if (curX == n - 1 && curY == m - 1)	return true;

		if (visited[curX][curY]) continue;
		visited[curX][curY] = true;

		for (int i = 0; i < 4; i++) {
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];
			if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < m &&
				!visited[nextX][nextY] && graph[nextX][nextY] == 1) {
				q.push({ nextX,nextY });
			}
		}
	}

	return false;
}

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> graph(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
			//뱀o->0, 뱀x->1
		}
	}

	if (solve(graph)) cout << 1;
	else cout << 0;

}