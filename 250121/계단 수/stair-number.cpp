#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MOD 1000000007

int main() {
	int n;
	cin >> n;
	
	//인접한 수의 차이가 모두 1인 수열 개수 구하기. 길이는 n
	vector<vector<int>> dp(n, vector<int>(10));
	//dp[i][j]: idx i번째 수를 고려중, 현재 숫자가 j(0-9)일때의 수열 개수
	dp[0][0] = 0; //0으로 시작하는 문자열은 없음
	for (int i = 1; i < 10; i++) {
		dp[0][i] = 1;
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j - 1 >= 0)dp[i][j] = (dp[i - 1][j - 1] + dp[i][j]) % MOD;
			if (j +1 <=9)dp[i][j] = (dp[i - 1][j + 1] + dp[i][j]) % MOD;
			
		}
	}

	int ans = 0;
	for (int j = 0; j < 10; j++) {
		ans = (ans + dp[n - 1][j]) % MOD;
	}
	cout << ans;
}
