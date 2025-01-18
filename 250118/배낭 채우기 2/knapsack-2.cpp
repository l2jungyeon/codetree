#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	//배낭문제.
	//근데 중복으로 선택이 가능한...

	vector<vector<int>> vec(n, vector<int>(2)); //0->무게, 1->가치
	for (int i = 0; i < n; i++) {
		cin >> vec[i][0] >> vec[i][1];
	}

	vector<int> dp(m + 1,0); //idx 무게일 때의 최대 가치
	for (int j = 0; j < m+1; j++) { //각 무게당
		for (int i = 0; i < n; i++) {//각 보석마다
			if (j >= vec[i][0])
				dp[j] = max(dp[j - vec[i][0]] + vec[i][1], dp[j]);
		}
	}

	/*for (int i = 0; i < m + 1; i++) {
		cout << dp[i] << endl;
	}*/

	cout << dp[m];
}
