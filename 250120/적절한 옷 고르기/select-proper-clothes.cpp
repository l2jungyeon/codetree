#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

int main() {

	//1. 만족도 차이의 합, 2. 현재 고려중인 날, 3.이전날의 만족도
	//dp[i][j] = i번째 날까지의 최대합, 오늘 j번째 옷을 입음

	int n, m;
	cin >> n >> m;

	vector<vector<int>> time(n, vector<int>(2)); //0은 입기시작, 1은 마지막날짜
	vector<int> vec(n); //화려함 지수
	for (int i = 0; i < n; i++) {
		cin >> time[i][0] >> time[i][1] >> vec[i];
	}

	vector<vector<int>> dp(m + 1, vector<int>(n, 0));
	dp[0][0] = 0;

	for (int i = 2; i <= m; i++) { //지금 날짜
		for (int j = 0; j < n; j++) { //오늘 입을 옷의 idx
			if (time[j][0] > i || time[j][1] < i) continue;

			for (int k = 0; k < n; k++) {//어제 입은 옷 고르기
				if (time[k][0] <= i-1 && time[k][1] >= i-1) {
					//if (k == j) dp[i][j] = dp[i - 1][k]; //똑같은옷 입으면 절댓값은 0
					dp[i][j] = max({ dp[i][j], dp[i - 1][k] + abs(vec[k] - vec[j])});
				}
			}

			//cout << dp[i][j] << " ";
		}
		//cout << endl;
	}

	int ans = INT_MIN;
	for (int i = 0; i < n; i++) {
		ans = max(ans, dp[m][i]);
	}
	cout << ans;
}
