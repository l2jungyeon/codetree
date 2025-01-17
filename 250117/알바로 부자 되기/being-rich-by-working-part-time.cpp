#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<pair<int, int>> vec(n);
	vector<int> cost(n);

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b >> cost[i];
		vec[i] = { a,b };
	}

	vector<int> dp(n);
	for (int i = 0; i < n; i++) {
		dp[i] = cost[i];
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (vec[j].second < vec[i].first) {//안겹치면
				dp[i] = max({ dp[j] + cost[i], dp[i] });
			}
		}
	}

	// for (int i = 0; i < n; i++) {
	// 	cout << dp[i]<<endl;
	// }
	sort(dp.begin(), dp.end());
	cout << dp[n - 1];
}
