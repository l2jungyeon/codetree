#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}

	vector<vector<int>> dp(n, vector<int>(21, 0));
	//dp[i][j]=idx i까지 고려시 |j|를 만들 수 있는 경우의 수

	dp[0][vec[0]] = 2;

	for (int i = 1; i < n; i++) { //각 idx에 대해서
		int curNum = vec[i];

		for (int j = 0; j < 21; j++) {
			if (dp[i - 1][j] > 0) {
				int preNum = j;
				if (curNum + preNum <= 20)
					dp[i][curNum + preNum] += dp[i - 1][j];
				if (abs(curNum - preNum) >= 0)
					dp[i][abs(curNum - preNum)] += dp[i - 1][j];
			}
		}
	}

	if (m == 0)cout << dp[n - 1][m];
	else cout << dp[n - 1][m] / 2;
}
