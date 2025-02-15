#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

//거쳐간 숫자의 최댓값
int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int n = triangle.size();
    
    vector<vector<int>> dp(n,vector<int>(n, INT_MIN));
    
    for(int i=0;i<n;i++) dp[n-1][i] = triangle[n-1][i];
    
    for(int i=n-2;i>=0;i--){ //밑에서부터 채우기
        int temp=INT_MIN;
        for(int j=0;j<i+1;j++){
            dp[i][j] = triangle[i][j] + max(dp[i+1][j],dp[i+1][j+1]);
        }
    }
    
    answer = dp[0][0];
    return answer;
}