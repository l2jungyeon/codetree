#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {

	int n;
	cin >> n;

	vector<int> vec(n);
	int m = 0;
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
		m += vec[i];
	}

	vector<bool> dp(m + 1,false);
	dp[0] = true;

	for (int i = 0; i < n; i++) {
		for (int j = m; j >= 0; j--) {
			if (j-vec[i]>=0 && dp[j - vec[i]] == true)
				dp[j] = true;
		}
	}

	for (int i = 0; i < m; i++) {
		if (dp[i] && m == 2 * i) {
			cout << "Yes";
			return 0;
		}
	}

	cout << "No";
}
