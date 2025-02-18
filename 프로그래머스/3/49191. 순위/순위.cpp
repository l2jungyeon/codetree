#include <string>
#include <vector>
using namespace std;

// 정확하게 순위를 매길 수 있는 선수의 수를 return 
//플로이드 워셜 알고리즘
int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    vector<vector<int>> map(n+1,vector<int>(n+1,0)); //idx 0은 안씀
    //연결 x:0, 
    // map[i][j]에서 i가 j를 이긴(i->j)경우: 1
    //map[i][j]에서 i가 j에게 진(i<-j)경우: 2
    for(int i=0;i<results.size();i++){
        int a=results[i][0];
        int b=results[i][1];
        
        map[a][b] = 1;
        map[b][a] = 2;
    }
    
    for(int k=1;k<=n;k++){ //k를 통한 갱신
        for(int i=1;i<=n;i++){ //i번째 사람
            for(int j=1;j<=n;j++){//k와 j의 관계
                if(map[k][j]==2&&map[i][k]==2){
                    map[i][j]=2;
                }
                if(map[k][j]==1&&map[i][k]==1){
                    map[i][j]=1;
                }
            }
        }
    }
    
    for(int i=1;i<=n;i++){
        int sum=0;
        for(int j=1;j<=n;j++){
            if(map[i][j]!=0) sum++;
        }
        if(sum>=n-1) answer++;
    }
    
    return answer;
}