#include <string>
#include <queue>
#include <vector>

using namespace std;

int check(vector<bool> visited){
    for(int i=0;i<visited.size();i++){
        if(visited[i]==false){
            return i;
        }
    }
    return -1; //모두 방문
}

int solve(const vector<vector<int>>& computers){
    int n = computers.size();
    queue<int> q;
    vector<bool> visited(n,false);
    
    q.push(0);
    int network=0;
    while(check(visited)!=-1){
        
        while(!q.empty()){
            int node = q.front();
            q.pop();

            if(visited[node]) continue;
            visited[node] = true;

            for(int i=0;i<n;i++){
                if(computers[node][i]==1){
                    q.push(i);
                }
            }
        }
        
        network++;
        q.push(check(visited));
    }
    
    return network;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    answer = solve(computers);
    return answer;
}