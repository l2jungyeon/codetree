#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <cmath>

using namespace std;

int count_func(int curNode, const vector<vector<int>>& wires){
    //송전탑의 개수를 세는
    //vec에 두 트리중 하나의 노드를 저장
    int n=wires.size();
    unordered_map<int,int> vec;
    
    queue<int> q;
    q.push(curNode);
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        for(int i=0;i<n;i++){
            if(wires[i][0]==cur){
                if(vec.find(wires[i][1])!=vec.end()) continue;
                q.push(wires[i][1]);
                vec[wires[i][1]] = 1;
            }
            else if(wires[i][1]==cur){
                if(vec.find(wires[i][0])!=vec.end()) continue;
                q.push(wires[i][0]);
                vec[wires[i][0]] = 1;
            }
        }
    }
    
    return vec.size();
}

//wires = n-1
//a+b=s/ a-b=a-(s-a)
int solution(int n, vector<vector<int>> wires) {
    int answer = 98;
    
    int j=n-1;
    //모든 전선을 하나씩 다 끊어보기
    while(j--){
        int curnode = wires[0][0];
        int curnode2 = wires[0][1];
        wires.erase(wires.begin());
        answer = min(answer, abs(2*count_func(curnode, wires)-n));
        wires.push_back({curnode,curnode2});
    }
    
    // 송전탑 개수의 차이(절대값)를 return 
    return answer;
}