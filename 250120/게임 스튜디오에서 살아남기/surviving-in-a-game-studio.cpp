#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
#define MOD 1000000007

int main() {
	int n;
	cin >> n;

	vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(4, vector<ll>(4, 0)));
	//dp[i][j][k]: i번째 날까지에 T를 j번, B를 k번연속 받은경우

	dp[1][0][0] = 1;
	dp[1][0][1] = 1;
	dp[1][1][0] = 1;

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= 2; j++) { //t를 받은 횟수
			for (int k = 0; k <= 2; k++) {//연속으로 b를 받은 횟수
				dp[i+1][j][0] = (dp[i][j][k] + dp[i + 1][j][0]) % MOD; //i+1번째 날에 g를 받은 경우

				dp[i+1][j+1][0] = (dp[i][j][k] + dp[i + 1][j + 1][0]) % MOD;//t받은

				dp[i+1][j][k+1] = (dp[i][j][k] + dp[i + 1][j][k + 1]) % MOD; //b받은
				
			}
		}
	}

	// 최종 결과를 계산합니다.
	int ans = 0;
	for (int j = 0; j < 3; j++) {
		for (int k = 0; k < 3; k++) {
			ans = (ans + dp[n][j][k]) % MOD;
		}
	}

	// 결과를 출력합니다.
	cout << ans;
}
