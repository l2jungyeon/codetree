#include <string>
#include <vector>
#include <iostream>
#define MOD 1000000007

using namespace std;

//오른쪽과 아래쪽으로만 움직여 집에서 학교까지 갈 수 있는 최단경로의 개수
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    //dp[i][j] : (i,j)에서 출발했을 때 도착지까지 갈 수 있는 경로의 개수
    //puddles의 x와 y의 좌표는 다 -1을 해줘야함
    vector<vector<int>> dp(n,vector<int>(m,-1));
    
    for(int k=0;k<puddles.size();k++){ //웅덩이 체크
        dp[puddles[k][1]-1][puddles[k][0]-1] = 0;
    }
    
    //초기화
    int flag=1;
    for(int j=m-1; j>=0; j--) {
        if(dp[n-1][j] == 0) flag = 0;
        dp[n-1][j] = flag;
    }
    
    flag=1;
    for(int j=n-1; j>=0; j--) {
        if(dp[j][m-1] == 0) flag = 0;
        dp[j][m-1] = flag;
    }
    
    for(int i=n-2;i>=0;i--){
        for(int j=m-2;j>=0;j--){
            if(dp[i][j]==0) continue;
            dp[i][j] = (dp[i+1][j]+dp[i][j+1])%MOD;
        }
    }
    
    answer = dp[0][0];
    return answer;
}