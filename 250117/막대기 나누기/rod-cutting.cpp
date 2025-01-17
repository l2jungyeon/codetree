#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> vec(n + 1); //길이가 idx인 막대기의 수익
	for (int i = 1; i <= n; i++) {
		cin >> vec[i];
	}

	vector<int> dp(n + 1);//idx i인 막대기의 최대 수익
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = vec[i];
	}

	for (int i = 1; i < n + 1; i++) {//막대기별로
		for (int j = 0; j < i; j++) {
			if (i-j>=0)
				dp[i] = max(dp[i - j] + vec[j], dp[i]);
		}
	}

	cout << dp[n];
}
