#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

#define MAX_N 100000
int vec[MAX_N][3];

int main() {
	int n;
	cin >> n;

	//vector<vector<int>> vec(n, vector<int>(3));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> vec[i][j];
		}
	}

	//dp[i][j] = i,j를 선택했을 때 최대 점수
	//0이면 0,1 , 1이면 상관없음, 2이면 1,2
	
	int prevdp[3];//큰거
	int prevdpS[3]; //작은거
	for (int i = 0; i < 3; i++) {
		prevdp[i] = vec[0][i];
		prevdpS[i] = vec[0][i];
	}

	for (int i = 1; i < n; i++) {//각 행 마다
		int dp[3];
		int dps[3];

		for (int j = 0; j < 3; j++) {//각 원소마다
			int num = vec[i][j];
			int smallNum = vec[i][j];

			if (j == 0) num += max(prevdp[0], prevdp[1]);
			else if (j == 2) num += max(prevdp[2], prevdp[1]);
			else if (j == 1) num += max({prevdp[0], prevdp[1], prevdp[2]});
			dp[j] = num;

			//작은거
			if (j == 0) smallNum += min(prevdpS[0], prevdpS[1]);
			else if (j == 2) smallNum += min(prevdpS[2], prevdpS[1]);
			else if (j == 1) smallNum += min({ prevdpS[0], prevdpS[1], prevdpS[2] });
			dps[j] = smallNum;

		}
		for (int j = 0; j < 3; j++) {
			prevdp[j] = dp[j];
			prevdpS[j] = dps[j];
		}
	}

	int large = -1; int small = INT_MAX;
	for (int j = 0; j < 3; j++) {
		large = max(prevdp[j], large);
		small = min(prevdpS[j], small);
	}

	cout << large << " " << small;
	return 0;
}