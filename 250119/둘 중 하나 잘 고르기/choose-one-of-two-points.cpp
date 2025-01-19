#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> red(2 * n);
	vector<int> blue(2 * n);

	for (int i = 0; i < n * 2; i++) {
		cin >> red[i] >> blue[i];
	}

	vector<vector<int>> dp(n + 1, vector<int>(2 * n));
	//dp[i][j] = j번째까지 고려하고 빨간색을 i개 뽑았을 때 r+b의 최대합
	dp[0][0] = blue[0];
	dp[1][0] = red[0];
	for (int i = 1; i < n; i++) dp[0][i] = dp[0][i - 1] + blue[i];

	for (int i = 1; i <= n; i++) {
		for (int j = i-1; j < n+i; j++) {
			if (j == i - 1) {
				if(i != 1)
					dp[i][j] = dp[i - 1][j - 1] + red[j];
				continue;
			}

			dp[i][j] = max(dp[i - 1][j - 1] + red[j], dp[i][j - 1] + blue[j]);
		}
	}

	/*for (int i = 0; i < n+1; i++) {
		for (int j = 0; j < 2 * n; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/

	cout << dp[n][2 * n - 1];
}
