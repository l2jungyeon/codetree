#include <iostream>
#include <vector>

typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<ll> dp(n); //dp[i] = idx 1부터 i까지의 누적합

    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        if (i != 0) dp[i] = dp[i - 1] + a;
        else dp[i] = a;
    }

    while (m--) {
        int a, b;
        cin >> a >> b;

        if (a - 2 < 0) cout << dp[b-1] << "\n";
        else cout << dp[b-1] - dp[a - 2] << "\n";
    }

}