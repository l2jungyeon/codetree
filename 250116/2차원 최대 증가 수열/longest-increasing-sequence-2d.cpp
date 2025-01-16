#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> vec(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> vec[i][j];
		}
	}

	vector<vector<int>> dp(n, vector<int>(m, INT_MIN));
	//i,j까지 왔을 때 밟을 수 있는 최대 칸 수
	dp[0][0] = 1;
	queue<pair<int, int>> q;
	q.push({ 0,0 });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = x+1; i < n; i++) {
			for (int j = y + 1; j < m; j++) {
				if (vec[x][y] < vec[i][j]) {
					dp[i][j] = max(dp[i][j], dp[x][y] + 1);
					q.push({ i,j });
				}
			}
		}
	}

	int large = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dp[i][j] > large) { large = dp[i][j]; }
		}
	}

    cout <<large;
}
