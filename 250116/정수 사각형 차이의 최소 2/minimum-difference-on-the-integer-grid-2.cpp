#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<vector<int>> vec(n, vector<int>(n));
	vector<tuple<int, int, int>> cell(n); //값,x,y

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> vec[i][j];
		}
	}
	
	vector < vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n)); //최솟값, 최댓값
	//가능한 경로상의 |최댓값-최솟값| 중 최솟값을 출력

	dp[0][0] = { vec[0][0],vec[0][0] };
	for (int i = 1; i < n; i++) {
		dp[i][0].first = min(dp[i - 1][0].first, vec[i][0]);
		dp[i][0].second = max(dp[i - 1][0].second, vec[i][0]);

		dp[0][i].first = min(dp[0][i - 1].first, vec[0][i]);
		dp[0][i].second = max(dp[0][i - 1].second, vec[0][i]);
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			int min1 = dp[i - 1][j].first;
			int min2 = dp[i][j - 1].first;
			int max1 = dp[i - 1][j].second;
			int max2 = dp[i][j - 1].second;

			if (max2 - min2 < max1 - min1) {
				dp[i][j].first = min2;
				dp[i][j].second = max2;
			}
			else {
				dp[i][j].first = min1;
				dp[i][j].second = max1;
			}

			if (dp[i][j].first > vec[i][j])	dp[i][j].first = vec[i][j];
			if (dp[i][j].second < vec[i][j]) dp[i][j].second = vec[i][j];

		}
	}

	cout << dp[n - 1][n - 1].second- dp[n - 1][n - 1].first;
}
