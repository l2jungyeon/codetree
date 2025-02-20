#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <unordered_map>

using namespace std;
//10 20
//10

void cleanpq(priority_queue<int,vector<int>,greater<>>& minq, priority_queue<int,vector<int>,less<>>& maxq, unordered_map<int,int>& map){
    while(!minq.empty()&& map[minq.top()]==0){
        minq.pop();
    }
     while(!maxq.empty()&& map[maxq.top()]==0){
        maxq.pop();
    }
}

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    int n = operations.size();
    
    priority_queue<int,vector<int>,less<>> maxq;
    priority_queue<int,vector<int>,greater<>> minq;
    unordered_map<int,int> map;
    
    for(int i=0;i<n;i++){
        if(operations[i][0]=='I'){
            int num = stoi(operations[i].substr(2,operations.size()-2));
            minq.push(num);
            maxq.push(num);
            if(map.find(num)!=map.end()){
                map[num]+=1;
            }
            else map[num]=1;
        }
        else{
            if(operations[i][2]=='1'){ //최댓값 삭제
                while(!maxq.empty() && map[maxq.top()]==0){
                    maxq.pop();
                }
                if(!maxq.empty()&& map[maxq.top()]!=0){
                    map[maxq.top()]--;
                    maxq.pop();
                }
            }
            else{//최솟값 삭제
                while(!minq.empty() && map[minq.top()]==0){
                    minq.pop();
                }
                if(!minq.empty()&& map[minq.top()]!=0){
                    map[minq.top()]--;
                    minq.pop();
                }
                cleanpq(minq,maxq, map);
            }
        }
    }
    
     cleanpq(minq,maxq, map);
    if(maxq.empty() || minq.empty()){
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        int maxn = maxq.top();
        int minn =minq.top();
        answer.push_back(maxn);
        answer.push_back(minn);
        }

    
    return answer;
}