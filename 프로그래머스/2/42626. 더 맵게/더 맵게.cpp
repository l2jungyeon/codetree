#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int n=scoville.size();
    
    priority_queue<int,vector<int>, greater<>> q;
    for(int i=0;i<n;i++){
        q.push(scoville[i]);
    }
    
    while(q.size()>=2 && q.top()<K){
        answer++;
        int a=q.top();
        q.pop();
        int b = q.top();
        q.pop();
        
        q.push(a+b*2);
    }
    
    if(q.top()<K) answer = -1;
    
    return answer;
}