#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int n;
	cin >> n;

	vector<int> vec(n);
	for (int i = 0; i < n; i++) cin >> vec[i];

	vector<int> dp(n);
	//dp[i]=idx i까지 고려했을 때 가장 많은 오름차순의 개수
	
	dp[0] = 1;
	int maxn = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i - 1; j >= 0; j--) { //이전꺼 탐색
			if (vec[j] < vec[i]) dp[i] = max(dp[j] + 1, dp[i]);
		}
		if (dp[i] == 0) dp[i] = 1;
		//cout << dp[i] << " ";
		maxn = max(dp[i], maxn);
	}

	cout << n - maxn;

}