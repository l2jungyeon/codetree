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

	//sort(vec.begin(), vec.end());

	vector<int> dp(m + 1, 10001); //idx i를 만드는데 필요한 원소의 최소 개수
	dp[0] = 0;
	for (int i = 0; i < n; i++) { //각 원소에 대해서
		for (int j = m; j > 0; j--) {
			if (j >= vec[i])
				dp[j] = min(dp[j - vec[i]] + 1, dp[j]);
		}
	}


	if (dp[m] == 10001) cout << "No";
	else cout << "Yes";
}
