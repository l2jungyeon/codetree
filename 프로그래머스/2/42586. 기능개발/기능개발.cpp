#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> leftday; //남은 날짜
    
    int n=progresses.size();
    
    for(int i=0;i<n;i++){
        leftday.push_back(((100-progresses[i])/speeds[i])+((100-progresses[i])%speeds[i]!=0?1:0));   
    }
    
    int maxday=leftday[0];
    int num=1;
    for(int i=1;i<n;i++){
        if(maxday>=leftday[i]) num++;
        else{
            answer.push_back(num);
            num=1;
            maxday=leftday[i];
        }
    }
    answer.push_back(num);
    
    return answer;
}