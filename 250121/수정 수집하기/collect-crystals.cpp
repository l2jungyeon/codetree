#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

int main() {
	int n, l;
	cin >> n >> l;
	
	vector<char> vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}
	//dp[k][i][j] j번째 수정, 현재 i번 움직임, 첫번째가 k(L,R)인경우
	vector<vector<vector<int>>> dp(2,vector<vector<int>>(l+1, vector<int>(n)));

	int ans = 0;

	for (int k = 0; k < 2; k++) {
		//k==0: 첫시작이 L
		//k==1: 첫시작이 R

		int p = 1;
		for (int i = 0; i < n; i++) {
			if (vec[i] == (k==0?'L':'R')) {
				if (i == 0 && vec[i] == 'R' && k == 1) continue;
				dp[k][0][i] += p;
				p++;
			}
		}

		for (int i = 1; i < l + 1; i++) {
			char preLR;
			if (k==0) preLR = i % 2 == 1 ? 'R' : 'L'; //움직인 후의 위치를 가정
			else preLR = i % 2 == 1 ? 'L' : 'R';

			for (int j = i; j < n; j++) {
				//이전 인덱스와 위치가 같다면 그대로+1
				if (preLR == vec[j]) {
					dp[k][i][j] = dp[k][i][j - 1] + 1;
				}
				else {//움직인 후의 위치와 다르다면
					//j번째에서 움직이기 vs 안움직이기
					dp[k][i][j] = max(dp[k][i - 1][j - 1] + 1, dp[k][i][j - 1]);
					if (dp[k][i][j] == dp[k][i - 1][j - 1] + 1) {
						preLR = vec[j];
					}
				}
			}
		}
		
		for (int i = 0; i < l + 1; i++) {
			ans = max(ans, dp[k][i][n - 1]);
		}
	}
	
	cout << ans;

}
