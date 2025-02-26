#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
int main() {
    int n;
    cin >> n;
    //0으로 시작하지 않고 1이 두번연속 나타나지x

    vector<ll> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i < n + 1; i++) {
        //i번째 자리가 0인 경우
        dp[i] += dp[i - 1];
        //i번째 자리가 1인 경우 -> i-1번째는 무조건 0
        dp[i] += dp[i - 2];
    }

    cout << dp[n];
}