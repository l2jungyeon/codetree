#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000003
using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    
    int n, k;
    cin >> n >> k;

// dp[i][j]: 현재 i번째 색을 고려중, 현재까지 선택한 색의 개수가 j개인 경우
    vector<vector<int>> dp1(n, vector<int>(k+1,0)); //첫번째 색을 선택
    vector<vector<int>> dp2(n, vector<int>(k + 1, 0));//첫번째 색 선택 x

    dp1[0][1] = 1; //첫번째 색상 하나 선택
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            
            if(j>0 && i>1)
                //i를 선택하는 경우 + i를 선택하지 않는 경우
                dp1[i][j] = (dp1[i - 2][j - 1] + dp1[i - 1][j]) % MOD;
            else dp1[i][j] = (dp1[i - 1][j]) % MOD; //i를 선택하지 않는 경우

        }
    }

    dp2[0][0] = 1; //첫번째 색상을 선택하지 x
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            //i를 선택하는 경우 + i를 선택하지 않는 경우
            if (j > 0) {
                if(i==1) dp2[i][j] = (dp2[i - 1][j - 1] + dp2[i - 1][j]) % MOD;
                else dp2[i][j] = (dp2[i - 2][j - 1] + dp2[i - 1][j]) % MOD;
            }
            else dp2[i][j] = (dp2[i - 1][j]) % MOD;

        }
    }

    //dp1의 경우, 첫번째 원소가 무조건 선택이 됐기 때문에 마지막원소는 절대 선택되면 안됨.
    //dp2는 마지막원소까지 고려
    cout << (dp1[n - 2][k] + dp2[n - 1][k])%MOD;
}