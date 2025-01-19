#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {

	//카드번호가 작은 사람의 카드 버리기+점수 얻기
	//점수의 최대합

	int n,k;
	cin >> n >> k;

	vector<int> vec(n);
	vector<int> minusIdx;
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
		if (vec[i] < 0)minusIdx.push_back(i);
	}


	int large = INT_MIN;
	vector<vector<int>> dp(k + 1, vector<int>(n));
	//dp[i][j]: 음수가 i개 이고 idx j까지 고려시 최대합
	int preIdx = -1;
	for (int i = 0; i < n; i++) {	//초기화
		if (vec[i] < 0) {
			preIdx = -1;
			continue;
		}
		else { dp[0][i] = vec[i];
		if (preIdx != -1) dp[0][i] += dp[0][preIdx];
		preIdx = i;
		}

        if (large < dp[0][i])large = dp[0][i];

	}

	for (int i = 1; i <= k; i++) {
		for (int j = minusIdx[i-1]; j < n; j++) {
			if (j == minusIdx[i-1]) {
				dp[i][j] = dp[i - 1][j - 1] + vec[j];
				continue;
			}

			if (vec[j] < 0) dp[i][j] = dp[i - 1][j - 1] + vec[j];
			if (vec[j] >= 0) dp[i][j] = dp[i][j - 1] + vec[j];

			if (large < dp[i][j])large = dp[i][j];
		}
	}

	cout << large;
}

//7 2
//8 - 1 - 2 6 4 - 9 10
