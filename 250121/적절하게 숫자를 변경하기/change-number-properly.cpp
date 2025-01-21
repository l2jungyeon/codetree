#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}

	//비슷한 수열 중 유사도가 가장 높은 수열의 유사도 출력
	//비슷한 수열: 인접한 두 숫자가 다른 횟수가 m번 이하
	//유사도: 같은 위치 같은 숫자의 개수
	//dp[i][j][k]: idx i까지 고려했을 때, 현재 숫자가 j일 때의 최대 유사도
	//				idx i 전까지 인접한 두 숫자가 다른 횟수가 k번
	//dp[i][j][k] = (dp[i-1][j][k] vs dp[i-1][j가아닌 다른 수][k-1]) + vec[i]와 비교

	vector<vector<vector<int>>> dp(n, vector<vector<int>>(5, vector<int>(m + 1)));
	
	for (int j = 1; j <= 4; j++) {
		dp[0][j][0] = (vec[0] == j ? 1 : 0);
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= 4; j++) {
			for (int k = 0; k < m + 1; k++) {
				dp[i][j][k] = dp[i - 1][j][k]; //이전과 현재의 숫자가 같은 경우

				if (k != 0) {
					for (int nj = 1; nj <= 4; nj++) {
						if (nj == j) continue;
						dp[i][j][k] = max(dp[i - 1][nj][k - 1], dp[i][j][k]); //이전과 현재의 숫자가 다른 경우
					}
				}

				if (vec[i] == j) dp[i][j][k] += 1;
			}
		}
	}

	int ans=0;
	for (int j = 1; j < 5; j++) {
		for (int k = 0; k < m + 1; k++) {
			ans = max(dp[n - 1][j][k], ans);
		}
	}
	cout << ans;

	/*for (int i = 0; i < n; i++) {
		for (int j = 1; j <= 4; j++) {
			for (int k = 0; k < m + 1; k++) {
				cout << dp[i][j][k] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}*/
}
