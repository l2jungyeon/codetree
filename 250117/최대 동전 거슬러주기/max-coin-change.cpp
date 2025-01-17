#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	//최대 동전의 수
	vector<int> vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}

	vector<int> dp(m + 1,INT_MIN);
	dp[0] = 0;
	for (int i = 1; i < m + 1; i++) {
		for (int j = 0; j < n; j++) {
			if(i>=vec[j])
				dp[i] = max(dp[i - vec[j]] + 1, dp[i]);
		}
	}

	if (dp[m] < 0) cout << "-1";
	else cout << dp[m];
}
