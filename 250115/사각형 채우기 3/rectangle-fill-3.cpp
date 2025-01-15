#include <iostream>
#include <vector>
using namespace std;
#define MOD 1000000007
typedef long long ll;

int main() {
    int n;
    cin>>n;
    vector<ll> dp(n+1);
    dp[1]=2;
    dp[2]=7;
    for(int i=3;i<n+1;i++){
        dp[i]=(dp[i-2]*4+dp[i-1]*2)%MOD;
    }
    cout <<dp[n];
    return 0;
}
//dp[3]=dp[1]*4+dp[2]*2=8+14