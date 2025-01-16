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

	vector<int> dp(n,INT_MIN);
	//dp[i] = idx i까지의 최대 점프 횟수

	dp[0] = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i;j++) {//마지막점프 idx
			if (j + vec[j] >= i) {//점프가 가능하다는 것
				dp[i] = max(dp[j] + 1, dp[i]);
			}
		}
	}
	sort(dp.begin(), dp.end());
	cout <<dp[dp.size() - 1];

}
