#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;

	vector<vector<int>> vec(n, vector<int>(2)); //[0]은 축구, [1]은 야구

	for (int i = 0; i < n; i++) {
		cin >> vec[i][0] >> vec[i][1];
	}

	vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(12, vector<int>(10, INT_MIN)));
	
	dp[0][0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 11; j++) {
			for (int k = 0; k <= 9; k++) {
				dp[i][j][k] = dp[i - 1][j][k];

				if (j > 0 && dp[i - 1][j - 1][k] != INT_MIN) {
					//이전상태에서 축구를 선택하는 경우
					dp[i][j][k] = max(dp[i - 1][j - 1][k] + vec[i-1][0], dp[i][j][k]);
				}
				if (k > 0 && dp[i - 1][j][k - 1] != INT_MIN) {
					//이전상태에서 야구를 선택하는 경우
					dp[i][j][k] = max(dp[i - 1][j][k - 1] + vec[i-1][1], dp[i][j][k]);
				}
			}
		}
	}

	cout << dp[n][11][9];
}
