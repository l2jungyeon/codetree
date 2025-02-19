#include <string>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

//  모든 섬이 서로 통행 가능하도록 만들 때 필요한 최소 비용
//mst찾는 문제 -> 프림 알고리즘

int solve(vector<vector<int>> map){
    int n=map.size();
    vector<bool> visited(n,false);
    vector<int> dist(n,INT_MAX);
    dist[0]=0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq; //dist와 idx
    pq.push({0,0});
    
    while(!pq.empty()){
        int curNode = pq.top().second;
        int curDist = pq.top().first;
        pq.pop();
        
        if(visited[curNode]) continue;
        visited[curNode]=true;
        
        for(int i=0;i<n;i++){
            //dist 배열 업데이트
            //+queue에 가장 작은 dist넣기
            if(!visited[i]&&map[curNode][i]!=0){
                dist[i]=min(dist[i],map[curNode][i]);
                pq.push({dist[i],i});
            }
        }
    }
    
    int sum=0;
    for(int i=0;i<dist.size();i++){
        if(dist[i]!=INT_MAX)   {sum+=dist[i]; }
        // cout << dist[i]<<endl;
    }
    return sum;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    vector<vector<int>> map(n,vector<int>(n));
    for(vector<int> vec:costs){
        int a=vec[0];
        int b=vec[1];
        int d = vec[2];
        map[a][b]=d;
        map[b][a]=d;
    }
    
    answer = solve(map);
    
    return answer;
}