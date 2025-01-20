#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
typedef long long ll;

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}

	int ans = INT_MIN;

	for (int startIdx = 0; startIdx <= n-(2*m-1); startIdx++) { //시작점에 따라
		//idx 0부터인것...
		vector<vector<ll>> dp(m + 1, vector<ll>(n, INT_MIN));
		//현재 i구간 선택 중 j번째 원소가 i구간의 마지막 최대 총합
		vector<vector<ll>> preMaxdp(m + 1, vector<ll>(n, INT_MIN));
		//이전 구간의 max값을 저장하는 벡터

		dp[1][startIdx] = vec[startIdx];
		preMaxdp[1][startIdx] = dp[1][startIdx];

		for (int i = startIdx + 1; i < n; i++) {
			dp[1][i] = dp[1][i - 1] + vec[i];

			preMaxdp[1][i] = max(preMaxdp[1][i - 1], dp[1][i]);
			if (startIdx == 3) {
				int l = true;
			}
		}

		for (int i = 2; i < m + 1; i++) { //현재 확인중인 구간에 따라
			for (int j = (i - 1) * 2 + startIdx; j < n; j++) {
				if (j == (i - 1) * 2 + startIdx) {
					dp[i][j] = dp[i - 1][j - 2] + vec[j];
					preMaxdp[i][j] = dp[i][j];
					continue;
				}

				dp[i][j] = max({ preMaxdp[i-1][j-2] + vec[j],dp[i][j - 1] + vec[j]});
				if (preMaxdp[i][j - 1] < dp[i][j])	preMaxdp[i][j] = dp[i][j];

			}
		}

		for (int j = 0; j < n; j++) {
			if (ans < dp[m][j]) ans = dp[m][j];
		}
	}
	
	cout << ans;
}

/*10 3
-300 -200 -600 -231 -997 -456 -10 -2 -3 -1
*/