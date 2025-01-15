#include <iostream>
#include <vector>
using namespace std;
#define MOD 10007

int main() {
    int n;
    cin>>n;
    vector<int> dp(n+1);
    dp[1]=1;
    dp[2]=2;
    dp[3]=3;
    for(int i=4;i<n+1;i++){
        dp[i]=(dp[i-1]+dp[i-2])%MOD;
    }
    cout<<dp[n];
    return 0;
}
//1=1
//2=11/2/2
//3=111/12/1+2=3
//4=1111/112/22/1+3+1=5
//5=11111/1112/122/1+4+3=8
//6=111111/11112/1122/222/1+5+6+113