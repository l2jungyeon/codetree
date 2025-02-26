#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    
    int n, w;
    cin >> n >> w;
    //t초동안 자두가 떨어짐, 최대 w번만 움직이기
    //나무는 1번 혹은 2번임

    vector<vector<int>> tree(n, vector<int>(3, 0)); //tree[i][1]=1 :i초에는  1번나무에서 사과가 떨어짐
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        tree[i][a] = 1;
    }

    vector<vector<int>> dp(n, vector<int>(w + 1, 0));
    //dp[i][j]=i번째 자두를 고려중일 때, j번 움직이고 난 후 받는 자두의 최대 개수
    //dp[i][j]=max(dp[i-1][j-1]+tree[i][1또는2], dp[i-1][j]+tree[i][1또는2])
    dp[0][0] = tree[0][1];
    for (int i = 1; i < n; i++) dp[i][0] = dp[i - 1][0] + tree[i][1];

    for (int j = 1; j < w + 1; j++) {
        int t = (j % 2) + 1;
        for (int i = j - 1; i < n; i++) {
            if (i - 1 >= 0) {
                dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + tree[i][t];
            }
            else {
                dp[i][j] = tree[i][t];
            }
        }
    }

    
    int ans = 0;
    for (int j = 0; j < w + 1; j++) {
        for (int i = 0; i < n; i++) {
            ans = max(dp[i][j], ans);
        }
    }
    cout << ans;
}