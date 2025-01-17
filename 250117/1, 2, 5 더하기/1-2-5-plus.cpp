#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
#define MOD 10007

int main() {
	int n;
	cin >> n;

	
	vector<int> vec = {1,2,5 };
	vector<int> dp(n + 1, 0);	//i를 1,2,5의 합으로 나타내는 방법의 수
	dp[0] = 1;
	for (int i = 1; i < n + 1; i++) {
		for (int j = 0; j < 3; j++) {
			if (i - vec[j] >= 0)
				dp[i] = (dp[i] + dp[i - vec[j]]) % MOD;
		}
	}

	cout << (dp[n]) % MOD;
}
