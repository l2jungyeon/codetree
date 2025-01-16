#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<vector<int>> vec(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> vec[i][j];
		}
	}

	vector<vector<int>> dp(n, vector<int>(n));
	//최솟값의 최댓값
	dp[0][0] = vec[0][0];
	for (int i = 1; i < n; i++)dp[i][0] = min(dp[i - 1][0], vec[i][0]);
	for (int i = 1; i < n; i++)dp[0][i] = min(dp[0][i - 1], vec[0][i]);

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			if (dp[i][j] > vec[i][j]) dp[i][j] = vec[i][j];
		}
	}

	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << dp[i][j]<<" ";
		}
		cout << endl;
	}*/

	cout << dp[n - 1][n - 1];
}
