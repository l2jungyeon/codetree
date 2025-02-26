#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;
using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<vector<ll>> vec(n, vector<ll>(2)); //vec[i][0]: 날짜, 1: 이익
    for (int i = 0; i < n; i++) {
        cin >> vec[i][0] >> vec[i][1];
    }

    vector<ll> dp(n + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        ll day = vec[i][0];
        ll coin = vec[i][1];

        if (i + day > n) {
            dp[i] = dp[i + 1];
            continue;
        }

        dp[i] = max(dp[i + day] + coin, dp[i+1]);
    }

    
    cout << dp[0];
}