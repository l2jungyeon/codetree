#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define MOD 10007

int main() {
	int n;
	cin >> n;
	vector<int> dp(46);
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i < n+1; i++) {
		dp[i] = dp[i - 2] + dp[i - 1];
	}
	cout << dp[n];
}
