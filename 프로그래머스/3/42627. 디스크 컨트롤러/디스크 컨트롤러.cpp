#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

bool check(vector<bool>visited){
    for(int i=0;i<visited.size();i++){
        if(!visited[i]) return false;
    }
    return true;
}

void push_short_req(priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>>& pq, const vector<vector<int>>& jobs, int& curTime, vector<bool>visited){
    //가장 요청시간이 짧은 애 넣기
    int minTime=10000;
    for(int i=0;i<jobs.size();i++){
        if(!visited[i] && minTime>jobs[i][0]){
            minTime = jobs[i][0];
        }
    }
    for(int i=0;i<jobs.size();i++){
        if(!visited[i] && minTime==jobs[i][0]){
            pq.push({jobs[i][1], jobs[i][0], i});
        }
    }
    curTime=minTime;
}

//  작업의 소요시간이 짧은 것, 작업의 요청 시각이 빠른 것, 작업의 번호가 작은 것 
int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int n = jobs.size();
    int curTime=0; //작업 시작 시간
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
    //소요시간, 요청시각, 작업 번호
    vector<bool>visited(n,false);
    
    push_short_req(pq,jobs, curTime,visited);
    
    
    int totalTime=0;
    
    while(!check(visited)){
        if(pq.empty()){
            push_short_req(pq,jobs,curTime,visited);
        }
        
        int t = get<0>(pq.top());
        int reqt=get<1>(pq.top());
        int idx = get<2>(pq.top());
        pq.pop();
        
        if(visited[idx]) continue;
        visited[idx]=true;
        
        curTime+=t;
        totalTime+=(curTime-reqt);
        
        for(int i=0;i<n;i++){ //요청시간이 된 애들 넣기
            if(!visited[i] && curTime>=jobs[i][0]){
                pq.push({jobs[i][1], jobs[i][0], i});
            }
        }
        
    }
    
    answer = totalTime/n;
    
    return answer;
}