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

	vector<vector<int>> dp(n, vector<int>(n));//현재칸까지의 최댓값 저장
	//최댓값을 최소로 하는!!
	//왼쪽, 위쪽, 해당칸의 숫자 중 최댓값을 저장
	dp[0][0] = vec[0][0];
	for (int i = 1; i < n; i++)dp[i][0] = max(dp[i-1][0], vec[i][0]);
	for (int i = 1; i < n; i++)dp[0][i] = max(dp[0][i-1], vec[0][i]);

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			dp[i][j] = min({ dp[i - 1][j], dp[i][j - 1] });
			if (dp[i][j] < vec[i][j]) dp[i][j] = vec[i][j];
		}
	}

	// for (int i = 0; i < n; i++) {
	// 	for (int j = 0; j < n; j++) {
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	cout << dp[n - 1][n - 1];
}
