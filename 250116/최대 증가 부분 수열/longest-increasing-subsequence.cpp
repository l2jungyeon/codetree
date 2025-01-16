#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}

	vector<int> dp(n,1);
	//dp[i] = idx i까지의 최장 증가 부분수열
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i;j++) {
			if (vec[j] < vec[i]) {
				dp[i] = max(dp[j] + 1, dp[i]);
			}
		}
	}

	sort(dp.begin(), dp.end());
	cout << dp[dp.size() - 1];

}
