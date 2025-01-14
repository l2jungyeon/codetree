#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

const int dx[] = { 0,0,1,-1 };
const int dy[] = { 1,-1,0,0 };

struct node {
	int x;
	int y;
	int time;
};

vector<vector<int>> bfs(vector<vector<int>> map, vector<pair<int, int>> tangerin) {
	int n = map.size();
	int k = tangerin.size();

	vector<vector<int>> timeMap(n, vector<int>(n, INT_MAX));
	queue<node> q; //상한귤 queue
	for (int i = 0; i < k; i++) {
		node nod;
		nod.x = tangerin[i].first; nod.y = tangerin[i].second; nod.time = 0;
		q.push(nod);

		vector<vector<bool>> visited(n, vector<bool>(n, false));

		while (!q.empty()) {
			int x = q.front().x;
			int y = q.front().y;
			int time = q.front().time;
			q.pop();

			if (visited[x][y]) continue;
			visited[x][y] = true;
			timeMap[x][y] = min(timeMap[x][y], time);

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx >= 0 && nx < n && ny >= 0 && ny < n
					&& map[nx][ny] == 1) {
					node noo;
					noo.x = nx; noo.y = ny; noo.time = time + 1;
					q.push(noo);
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (timeMap[i][j] == INT_MAX) {
				if (map[i][j] == 0) timeMap[i][j] = -1;
				else if (map[i][j] == 1) timeMap[i][j] = -2;
			}
		}
	}

	return timeMap;
}

int main() {
	int n, k;
	cin >> n >> k;

	vector<vector<int>> map(n, vector<int>(n));
	vector<pair<int, int>> tangerin;//초기 상한 귤들의 좌표
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			//0: 귤없음
			//1: 귤잇음 2: 상한귤잇음
			if (map[i][j] == 2)tangerin.push_back({ i,j });
		}
	}

	vector<vector<int>> timemap = bfs(map, tangerin);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << timemap[i][j] << " ";
		}
		cout << "\n";
	}

}