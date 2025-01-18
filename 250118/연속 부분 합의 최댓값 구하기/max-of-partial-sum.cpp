#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int arr[100000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> dp(n);//idx까지 고려시 최대 부분합
    dp[0]=arr[0];
    for(int i=1;i<n;i++){
        dp[i]=max(dp[i-1]+arr[i],arr[i]);
    }

    sort(dp.begin(),dp.end());
    cout << dp[n-1];

    return 0;
}
