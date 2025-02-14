#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int maxGo=0;

void solve(int curK, int cnt, const vector<vector<int>>& dungeons, vector<bool> visited){    
    int n = dungeons.size();//던전 개수
    bool torf = false;
    for(int i=0; i<n; i++){
        int nextmin = dungeons[i][0];
        int nextK = curK-dungeons[i][1];
        if(!visited[i] && nextmin<=curK){
            torf=true;
            visited[i]=true;
            solve(nextK,cnt+1,dungeons, visited);
            visited[i]=false;
        }
    }
    
    if(!torf){ //더이상 갈 던전이 없을 때
        maxGo = max(maxGo,cnt);
        return;
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    
    int n = dungeons.size();//던전 개수
    vector<bool> visited(n, false);
    
    solve(k,0,dungeons,visited);
    answer = maxGo;
    
    return answer;
}