#include <iostream>
#include <vector>
using namespace std;
#define MOD 10007

int main() {
    int n;
    cin>>n;

    vector<int> dp(n+1);
    dp[1]=0;
    dp[2]=1;
    dp[3]=1;
    for(int i=4;i<n+1;i++){
        if(dp[i-2]!=0) dp[i]++;
        if(dp[i-3]!=0) dp[i]++;
        dp[i]=dp[i-2]+dp[i-3];
    }
    cout << dp[n];
    return 0;
}