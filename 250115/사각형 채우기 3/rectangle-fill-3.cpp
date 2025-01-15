#include <iostream>
#include <vector>
using namespace std;
#define MOD 1000000007
typedef long long ll;

int main() {
    int n;
    cin>>n;
    vector<ll> dp(n+1);
    dp[0]=1;
    dp[1]=2;
    dp[2]=7;
    for(int i=3;i<n+1;i++){
        dp[i]=(dp[i-2]*3)%MOD;
        for(int j=0;j<i;j++){
            if(j!=i-2) dp[i]+=(dp[j]*2)%MOD;
        }
    }
    cout <<dp[n];
    return 0;
}
//dp[3]=dp[1]*4-1+dp[2]*2=8+14
//22
//dp[4]=dp[2]*4+dp[3]*