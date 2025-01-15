#include <iostream>
#include <vector>
using namespace std;
#define MOD 10007

int main() {
    int n;
    cin>>n;
    vector<int> dp(n+1);
    dp[0]=1;
    dp[1]=1;
    dp[2]=3;
    for(int i=3;i<n+1;i++){
        dp[i] = (dp[i-1]*1+dp[i-2]*2)%MOD;
    }
    cout << dp[n];
    return 0;
}
//3 dp[1]*2+dp[2]*1
//4 dp[2]