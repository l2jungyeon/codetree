#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}

	vector<int> dp(m+1,10001);
	//dp[i]=i원인경우 최소 동전의 수
	dp[0] = 0;
	for (int i = 1; i <= m; i++) {//dp[i]
		for (int c = 0; c < n; c++) {//기존 동전과의 비교
			if(i>=vec[c])
				dp[i] = min(dp[i],dp[i-vec[c]]+1);
		}
	}

	if (dp[m] == 10001) cout << -1;
	else cout << dp[m];
}
