#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool solve(string curNode, vector<vector<string>> map, vector<vector<int>>& visited, vector<string>& vec){
    bool flag = false;
    for(int i=0;i<visited.size();i++){
        for(int j=1;j<visited[i].size();j++){
            if(visited[i][j]==0){ //(첫번째 노드 제외) 하나라도 방문하지 않았다면
                flag=true;
            }
        }
    }
    if(!flag) //모두 방문했다면
        return true;
    
    for(int i=0;i<map.size();i++){
        if(map[i][0]==curNode){
            for(int j=1;j<map[i].size();j++){
                if(visited[i][j]==0){
                    visited[i][j]=1;
                    vec.push_back(map[i][j]);
                    
                    if(solve(map[i][j], map,visited,vec)){
                        return true;   
                    }
                    
                    vec.erase(vec.end()-1);
                    visited[i][j]=0;
                }
            }
        }
    }
    
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    //인접행렬리스트 만들기
    //그후 각 리스트를 sort(알파벳순)하기
    
    vector<vector<string>> map;
    for(int i=0;i<tickets.size();i++){
        bool flag = false;
        for(int j=0;j<map.size();j++){
            if(map[j][0] == tickets[i][0]){
                map[j].push_back(tickets[i][1]);
                flag=true;
                break;
            }
        }
        if(!flag){
            map.push_back(tickets[i]);
        }
    }
    
    for(int i=0;i<map.size();i++){
        sort(map[i].begin()+1,map[i].end());
    }
    
    vector<vector<int>> visited(map.size());
    for(int i=0;i<map.size();i++){
        for(int j=0;j<map[i].size();j++) 
            visited[i].push_back(0);
    }
    
    answer.push_back("ICN");
    solve("ICN",map,visited,answer);
    
    return answer;
}