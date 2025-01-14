#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int dx[] = { 0,0,-1,1 };
const int dy[] = { 1,-1,0,0 };

int bfs(vector<vector<int>> map) {
	int n = map.size();
	int m = map[0].size();

	vector<vector<bool>> visited(n, vector<bool>(m,false));
	vector<vector<int>> dist(n, vector<int>(m, 0));
	queue<pair<int, int>> q;
	q.push({ 0,0 });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		int d = dist[x][y];
		q.pop();

		if (visited[x][y]) continue;
		if (x == n - 1 && y == m - 1) return dist[x][y];
		visited[x][y] = true;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m
				&& !visited[nx][ny] && map[nx][ny] == 1) {
				dist[nx][ny] = d + 1; //거리 업데이트
				q.push({ nx,ny });
			}
		}
	}

	return -1;
}

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> map(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			//뱀이 있으면 0
		}
	}

	cout << bfs(map);
}