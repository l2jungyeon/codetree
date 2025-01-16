#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int dx[] = { 0,0,1,-1 };
const int dy[] = { 1,-1,0,0 };

int main() {
	int n;
	cin >> n;

	vector<vector<int>> vec(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> vec[i][j];
		}
	}

	vector<vector<int>> dp(n, vector<int>(n,1));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int curx = i;
			int cury = j;

			for (int d = 0; d < 4; d++) {
				int x = curx + dx[d];
				int y = cury + dy[d];

				if (x < n && x >= 0 && y < n && y >= 0){
					if (vec[x][y] > vec[curx][cury]) {//다음께 더 큰 경우
						dp[x][y] = max(dp[curx][cury] + 1,dp[x][y]);//다음 dp 업데이트
					}
					else if (vec[x][y] < vec[curx][cury]) {//다음께 더 작은 경우
						dp[curx][cury] = max(dp[x][y] + 1,dp[curx][cury]);
						//현재 dp 업데이트
					}
				}
			}
		}
	}
	
	int large = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (large < dp[i][j]) { large = dp[i][j]; }
		}
	}
	cout << large;

}
