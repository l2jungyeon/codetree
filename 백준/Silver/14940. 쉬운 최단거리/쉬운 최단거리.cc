#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int n, m;
int x, y; //목표지점

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

void solve(const vector<vector<int>>& map, vector<vector<int>>& dp) {
	//vector<vector<int>> dp(n, vector<int>(m));
	vector<vector<bool>> visited(n, vector<bool>(m,false));

	queue<pair<int, int>> q;

	q.push({ x,y });
	dp[x][y] = 0;
	visited[x][y] = true;

	while (!q.empty()) {
		int curx = q.front().first;
		int cury = q.front().second;
		int dist = dp[curx][cury];
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextX = curx + dx[i];
			int nextY = cury + dy[i];

			if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < m
				&& visited[nextX][nextY]==false
				&& map[nextX][nextY] != 0) { //다음꺼가 못가는 땅이 아니면
					dp[nextX][nextY] = dist + 1;
					q.push({ nextX,nextY });
					visited[nextX][nextY] = true;
			}
		}
	}
}

int main() {
	cin >> n >> m;
	vector<vector<int>> map(n, vector<int>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			//0은 갈 수 없는 땅이고 1은 갈 수 있는 땅, 2는 목표지점이다. 
			//입력에서 2는 단 한개
			//2부터 시작해서 각 지점까지의 거리를 계산하면 될듯
			if (map[i][j] == 2) {
				x = i;
				y = j;
			}
		}
	}

	//원래 갈 수 없는 땅 0을 출력하고, 
	// 원래 갈 수 있는 땅인 부분 중에서 도달할 수 없는 위치는 -1을 출력
	vector<vector<int>> dp(n, vector<int>(m));
	solve(map, dp);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1 && dp[i][j] == 0) cout << "-1" << " ";
			else cout << dp[i][j] << " ";
		}
		cout << "\n";
	}

}