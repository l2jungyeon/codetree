#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<vector<int>> vec(n, vector<int>(3)); //0왼 1가 2오
	for (int i = 0; i < n; i++) {
		cin >> vec[i][0] >> vec[i][1] >> vec[i][2];
	}

	vector<vector<int>> dp(n, vector<int>(3));
	//dp[i][j]: i번째층을 고려중일 때, i번째 층에서 j(왼,가,오)방을 선택하는 경우
	for (int j = 0; j < 3; j++) dp[0][j] = vec[0][j];
	
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			dp[i][j] = max(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]) + vec[i][j];
		}
	}

	int ans = 0;
	for (int j = 0; j < 3; j++) {
		ans = max(ans, dp[n - 1][j]);
	}

	cout << ans;

}
