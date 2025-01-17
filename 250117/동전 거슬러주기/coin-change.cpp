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
		for (int j = 0; j < i; j++) {//dp[j]와 비교
			dp[i] = min(dp[j] + dp[i - j], dp[i]);
		}
		for (int c = 0; c < n; c++) {//기존 동전과의 비교
			if (i % vec[c] == 0 && i / vec[c] > 0) {
				dp[i] = min(i / vec[c], dp[i]);
			}
		}
	}

	if (dp[m] == 10001) cout << -1;
	else cout << dp[m];
}
