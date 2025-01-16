#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int dx[] = { 0,0,1,-1 };
const int dy[] = { 1,-1,0,0 };

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<vector<int>> vec(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> vec[i][j];
		}
	}

	vector<vector<int>> dp(n, vector<int>(n,1));
	//인접한 칸이 자신보다 작으면 인접한칸dp +1
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			q.push({ i,j });
		}
	}

	while (!q.empty()) {
		int curx = q.front().first;
		int cury = q.front().second;
		q.pop();


		for (int d = 0; d < 4; d++) {
			int x = curx + dx[d];
			int y = cury + dy[d];

			if (x < n && x >= 0 && y < n && y >= 0){
				if (vec[x][y] > vec[curx][cury]) {//다음께 더 큰 경우
					dp[x][y] = dp[curx][cury] + 1;
					q.push({ x,y });
				}
				else if (vec[x][y] < vec[curx][cury]) {//다음께 더 작은 경우
					dp[curx][cury] = max(dp[x][y] + 1,dp[curx][cury]);
				}
			}
		}
	}

	/*cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/


	int large = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (large < dp[i][j]) { large = dp[i][j]; }
		}
	}
	cout << large;

}
