#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//70 20 10 90
//90 70 20 10
//이 경우에는 70+20 / 90+10으로 가야함

bool compare(int a,int b){
    return a>b;
}

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    //가장 큰거랑 가장 작은거를 합치기
    //만약 limit을 넘기면 가장 큰애는 혼자 태우기
    
    sort(people.begin(),people.end(),compare);
    for(int i=0;i<people.size();i++){
        int large=people[i];
        int small=people[people.size()-1];
        
        if(large+small > limit){
            answer++;
        }
        else{
            answer++;
            people.erase(people.end()-1);
        }
    }
    
    return answer;
}