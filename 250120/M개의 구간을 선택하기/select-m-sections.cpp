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

    for (int startIdx = 0; startIdx <= n - (2 * m - 1); startIdx++) {
        vector<vector<ll>> dp(m + 1, vector<ll>(n, INT_MIN));
        dp[1][startIdx] = vec[startIdx];

        // Precompute max values for dp[i-1][j-2]
        vector<ll> maxPrev(n, INT_MIN);
        maxPrev[startIdx] = vec[startIdx];
        for (int i = startIdx + 1; i < n; i++) {
            maxPrev[i] = max(maxPrev[i - 1], dp[1][i]);
        }

        for (int i = 2; i <= m; i++) {
            vector<ll> maxDp(n, INT_MIN);
            for (int j = (i - 1) * 2 + startIdx; j < n; j++) {
                if (j >= 2) {
                    dp[i][j] = maxPrev[j - 2] + vec[j];
                }
                maxDp[j] = max(maxDp[j - 1], dp[i][j]);
            }
            maxPrev = maxDp;
        }

        for (int j = 0; j < n; j++) {
			if (ans < dp[m][j]) ans = dp[m][j];
        }
    }

    cout << ans;
    return 0;
}
