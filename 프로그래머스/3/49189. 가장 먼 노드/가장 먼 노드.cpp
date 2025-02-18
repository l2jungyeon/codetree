#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
//dfs
// void solve(int depth, int curNode, vector<bool>& visited, const vector<vector<int>>& map){
//     if(maxDepth<depth){
//         maxDepth = depth;
//         ansvec.clear();
//         ansvec.push_back(curNode);
//     }
//     else if(maxDepth==depth){
//         ansvec.push_back(curNode);
//     }
    
//     int n = map.size()-1;
//     for(int i=1;i<=n;i++){
//         if(!visited[i] && map[curNode][i] == 1){
//             visited[i]=true;
//             solve(depth+1, i,visited,map);
//         }
//     }
    
//     //더이상 갈 곳이 없으면 return
//     return;
// }

//bfs
vector<int> solve(const vector<vector<int>>& map){
    int n=map.size()-1;
    queue<pair<int,int>> q; //depth, curNode
    vector<bool> visited(n+1,false); //idx 0은 안씀
    
    q.push({0,1});
    
    vector<int> ansvec(n+1,0); // 각 노드의 거리 구하기
    
    while(!q.empty()){
        int depth = q.front().first;
        int curNode = q.front().second;
        q.pop();
        
        if(visited[curNode]) continue;
        visited[curNode]=true;
        
        ansvec[curNode] = depth;
        
        for(int i=1;i<=n;i++){
            if(!visited[i] && map[curNode][i] == 1){
                q.push({depth+1,i});
            }
        }
        
    }
    
    return ansvec;
}


// 1번 노드로부터 가장 멀리 떨어진 노드가 몇 개인지를 return 
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    //인접행렬
    vector<vector<int>> map(n+1,vector<int>(n+1,0));
    //idx 0은 안씀
    for(int i=0;i<edge.size();i++){
        int a = edge[i][0];
        int b = edge[i][1];
        
        map[a][b]=1;
        map[b][a]=1;
    }
    
    vector<bool> visited(n+1,false); //idx 0은 안씀
    visited[0]=true;
    visited[1]=true;
    
    vector<int> ansvec = solve(map);
    
    sort(ansvec.begin(),ansvec.end(), greater<>());
    int maxDepth=ansvec[0];
    answer=1;
    
    for(int i=1;i<n+1;i++){
        // cout << ansvec[i]<<" ";
        if(maxDepth>ansvec[i]) break;
        else answer++;
    }
    
    return answer;
}