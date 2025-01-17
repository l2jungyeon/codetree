#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> vec(n, vector<int>(2));//[i][0]: 무게/ [i][1]: 가치
	for (int i = 0; i < n; i++) {
		cin >> vec[i][0] >> vec[i][1];
	}

	
	vector<int> dp(m+1);//무게 i일때 최대 가치
	dp[0] = 0;
	for (int i = 0; i < n; i++) {//각 보석에 대해서 (하나씩만 고려)
		for (int j = m; j >= 0; j--) {
			if (j >= vec[i][0])
				dp[j] = max(dp[j - vec[i][0]] + vec[i][1], dp[j]);
		}
	}

	cout << dp[m];
}
