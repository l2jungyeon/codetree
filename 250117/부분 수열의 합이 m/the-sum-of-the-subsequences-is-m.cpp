#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	//합이 m인 부분수열의 최소 길이 -> 각 숫자를 한개씩만 사용하면 됨.
	//순서는 딱히..? 가장 작은것부터 사용하면 되는거 아닌가

	vector<int> vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}

	sort(vec.begin(), vec.end());

	vector<int> dp(m + 1, INT_MAX);
	dp[0] = 0;
	for (int i = 0; i < n; i++) {//각 원소에 대해서
		for (int j = m; j >= 0; j--) {
			if (j >= vec[i]&& dp[j-vec[i]]!= INT_MAX) {
				dp[j] = min(dp[j], dp[j - vec[i]] + 1);
			}
		}
	}

	if(dp[m]==INT_MAX) cout << "-1";
    else cout << dp[m];


}
