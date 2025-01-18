#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	//1계단(딱 3번까지만 가능) 또는 2계단
	//동전 개수의 최대합

	int n;
	cin >> n;

	vector<int>vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}

	if (n <= 2) {
		cout << vec[0] + vec[1];
		return 0;
	}

	//dp[i][j]=1계단을 i개 올랐고, j번째 계단까지 고려했을 때의 최대합
	//dp[i][j] = max(dp[i-1][j-1]+vec[i], dp[i][j-1],dp[i][j])
	//j번째 계단을 오르는 경우(한계단 오르기) or j번째 계단을 오르지 않는 경우(두계단 오르기)
	//j-1번째 계단에서 2계단을 오르는 경우
	vector<vector<int>> dp(4, vector<int>(n));
	dp[0][0] = 0;
	dp[0][1] = vec[1];
	dp[1][0] = vec[0];
	dp[2][1] = vec[0] + vec[1];
	dp[3][2] = vec[0] + vec[1] + vec[2];

	for (int i = 2; i < n; i++) { //1계단을 0개 올랐고, i번째 계단까지 고려
		if (i % 2 == 0) dp[0][i] = 0;
		else dp[0][i] = dp[0][i - 2] + vec[i];
	}

	for (int i = 1; i < 4; i++) { //1계단을 i개 올랐고, j번째 계단까지 고려
		for (int j = i; j < n; j++) {
			if (j == n - 1) dp[i][j] = max({ dp[i][j], dp[i][j - 2] + vec[j],dp[i - 1][j - 1] + vec[j] });
			else {
				dp[i][j] = max({ dp[i - 1][j - 1] + vec[j],dp[i][j - 1] ,dp[i][j] });
				if (j - 2 >= 0)dp[i][j] = max(dp[i][j], dp[i][j - 2] + vec[j]);
			}

		}
	}

	cout << dp[3][n - 1];
}
