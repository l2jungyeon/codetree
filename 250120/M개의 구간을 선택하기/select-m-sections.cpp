#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
typedef long long ll;

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}

	int ans = INT_MIN;

	for (int startIdx = 0; startIdx <= n-(2*m-1); startIdx++) {
		//idx 0부터인것...
		vector<vector<ll>> dp(m + 1, vector<ll>(n, INT_MIN));
		dp[1][startIdx] = vec[startIdx];
		for (int i = startIdx+1; i < n; i++) dp[1][i] = dp[1][i - 1] + vec[i];

		for (int i = 2; i < m + 1; i++) {
			for (int j = (i - 1) * 2 + startIdx; j < n; j++) {
				if (j == (i - 1) * 2 + startIdx) {
					dp[i][j] = dp[i - 1][j - 2] + vec[j];
					continue;
				}
				for (int maxJ = (i - 1) * 2 + startIdx-2; maxJ < j-1; maxJ++){
					dp[i][j] = max({ dp[i - 1][maxJ] + vec[j], dp[i][j - 1] + vec[j],dp[i][j] });
				}
			}
		}
		
			// for (int i = 1; i < m + 1; i++) {
			// 	for (int j = 0; j < n; j++) {
			// 		cout << dp[i][j] << " ";
			// 	}
			// 	cout << endl;
			// }
			// cout << endl;
		
		for (int j = 0; j < n; j++) {
			if (ans < dp[m][j]) ans = dp[m][j];
		}
	}
	
	cout << ans;
}

/*10 3
-300 -200 -600 -231 -997 -456 -10 -2 -3 -1
*/