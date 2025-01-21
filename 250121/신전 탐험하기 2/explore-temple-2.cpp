#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<vector<int>> vec(n, vector<int>(3));//0왼 1가 2오
	for (int i = 0; i < n; i++) {
		cin >> vec[i][0] >> vec[i][1] >> vec[i][2];
	}

	vector<vector<vector<int>>> dp(3,vector<vector<int>>(n, vector<int>(3)));
	// dp[k][i][j]:1번째 층의 방향이 k이고,
	// i번째층을 고려중일 때, i번째 층에서 j(왼,가,오)방을 선택하는 경우
	//n층과 1층의 방향이 같으면 안됨

	for (int j = 0; j < 3; j++) {
		dp[j][0][j] = vec[0][j];
		dp[j][0][(j + 1) % 3] = INT_MIN;
		dp[j][0][(j + 2) % 3] = INT_MIN;

	}

	int ans = 0;
	for (int k = 0; k < 3; k++) {
		for (int i = 1; i < n-1; i++) {
			for (int j = 0; j < 3; j++) {
				dp[k][i][j] = max(dp[k][i - 1][(j + 1) % 3], dp[k][i - 1][(j + 2) % 3]) + vec[i][j];
			}

		}
		//마지막방 처리
		dp[k][n - 1][(k + 1) % 3] = max(dp[k][n - 2][k], dp[k][n - 2][(k + 2) % 3]) + vec[n - 1][(k + 1) % 3];
		dp[k][n - 1][(k + 2) % 3] = max(dp[k][n - 2][k], dp[k][n - 2][(k + 1) % 3]) + vec[n - 1][(k + 2) % 3];
		ans = max({ ans,dp[k][n - 1][(k + 1) % 3],dp[k][n - 1][(k + 2) % 3] });
	}

	cout << ans;

}
