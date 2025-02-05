#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		vector<vector<int>> vec(2, vector<int>(n));
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cin >> vec[i][j];
			}
		}

		//dp[i][j]=j번째 col에서 i(0,1)을 골랐을 때 최대 합
		vector<vector<int>> dp(2, vector<int>(n));
		dp[0][0] = vec[0][0];
		dp[1][0] = vec[1][0];
		for (int j = 1; j < n; j++) {
			for (int i = 0; i < 2; i++) {
				dp[i][j] = dp[abs(i - 1)][j - 1] + vec[i][j];
				if (j - 2 >= 0) {
					dp[i][j] = max(dp[i][j], dp[abs(i - 1)][j - 2] + vec[i][j]);
				}
			}
		}

		int ans = 0;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				ans = max(ans, dp[i][j]);
			}
		}

		cout << ans << endl;
	}
}