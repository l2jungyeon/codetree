#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	
	vector<char> vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}

	//dp[i][j] = j번째 이전까지 i(0-k)번 움직였고 j번째 수정을 고려하고 있을 때
	vector<vector<int>> dp(k+1, vector<int>(n));

	int p = 1;
	for (int i = 0; i < n; i++) {
		if (vec[i] == 'L'){
			dp[0][i] += p;
			p++;
		}
	}
	dp[1][0] = 0;

	for (int i = 1; i < k+1; i++) {
		char preLR = i % 2 == 1 ? 'R' : 'L';
		for (int j = i; j < n; j++) {
			//이전 인덱스와 위치가 같다면 그대로+1
			if (preLR == vec[j]) {
				dp[i][j] = dp[i][j - 1] + 1;
			}
			else {//움직인 후의 위치와 다르다면
				//j번째에서 움직이기 vs 안움직이기
				dp[i][j] = max(dp[i - 1][j - 1] + 1, dp[i][j - 1]);
				if (dp[i][j] == dp[i - 1][j - 1] + 1) {
					preLR = vec[j];
				}
			}
		}
	}

	cout << dp[k][n-1];
}
