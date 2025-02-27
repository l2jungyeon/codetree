#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> coin(n);
        for (int i = 0; i < n; i++) cin >> coin[i];

        int m;
        cin >> m; //만들어야할 금액
        //N가지 동전으로 금액 M을 만드는 모든 방법의 수

        vector<int> dp(m + 1, 0);
        //dp[i]: i원을 만드는 방법의 개수
        dp[0] = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < m + 1; j++) {
                if (j - coin[i] >= 0) dp[j] += dp[j - coin[i]];
            }
        }

        cout << dp[m] << endl;
    }
}