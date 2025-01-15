#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> dp(20,0);
    dp[0]=1;
    dp[1] =1;
    dp[2]=2;
    dp[3]=5;
    for(int i=4;i<n+1;i++){
        int cnt = i-1;
        for(int j=0;j<i;j++){
            dp[i] += dp[cnt]*dp[j];
            cnt--;
        }
    } 
    cout << dp[n];
    return 0;
}
//1 1
//2 2
//3 dp[2]*2+dp[1]*dp[1]=5 //11 20 02
//4 dp[3]*2+dp[2]*2=5*2+4=14 //13 22 31
//5 dp[4]*2+dp[3]*2+dp[2]*dp[2]
//6 dp[5]*2+dp[4]*2+dp[3]*dp[2]*2
//dp[i] = dp[i-1]*2+dp[i-2]*2+dp[i-3]*dp[2]