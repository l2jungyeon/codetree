#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    
    int size=words.size();
    vector<string> vec;
    
    //번호, 차례
    int person=1;
    int start=1;
    int idx = 0;
    
    while(idx!=size){
        if(idx!=0){
            //이전사람과 이어지는지
            if(words[idx-1][words[idx-1].size()-1] != words[idx][0]) break;
        } 
        
        //방문한곳을 또 방문했는지
        bool torf=true;
        for(int i=0;i<vec.size();i++){
            if(vec[i]==words[idx]) {torf = false; break;} 
        }
        if(!torf){
            break;
        }
        else {
            vec.push_back(words[idx]);
            person=(person+1)%(n+1);
            if(person==0) {
                person++; start++;}
            idx = (person-1)+(start-1)*n;
        }
        
    }
    
    if(idx==size) {answer.push_back(0); answer.push_back(0);}
    else{
        answer.push_back(person);
        answer.push_back(start);
    }

    return answer;
}