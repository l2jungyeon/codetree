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

	vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(12, vector<ll>(10,0)));
	//dp[i][j][k] i번째 학생을 고려중일 때, 축구,야구
	dp[0][1][0] = vec[0][0];
	dp[0][0][1] = vec[0][1];

	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= 11; j++) {
			for (int k = 1; k <= 9; k++) {
				dp[i][j][k] = max({ dp[i - 1][j - 1][k] + vec[i][0], 
					dp[i - 1][j][k - 1] + vec[i][1], dp[i - 1][j][k] });
			}
		}
	}

	cout << dp[n - 1][11][9];
}
