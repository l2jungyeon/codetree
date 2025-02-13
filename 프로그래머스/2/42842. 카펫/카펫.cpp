#include <string>
#include <vector>

using namespace std;

void solve(int brown, int yellow){
    
}

vector<int> solution(int brown, int yellow) {
    vector<int> answer; //가로, 세로 순서대로
    
    //8+8+4+4=16+8=24
    //가로*세로 = brown+yellow
    // int r=3;int c=3; //r은 가로, c는 세로
    int sum = brown+yellow;
    
    vector<pair<int,int>> rc; //가능한 가로세로 조합
    for(int i=1;i<sum;i++){
        if(sum%i==0 && sum/i>=i){
            rc.push_back({sum/i, i});
        }
    }
    
    for(int i=0;i<rc.size();i++){
        int r = rc[i].first;
        int c = rc[i].second;
        //(가로-1)*2+(세로-1)*2=brown && (가로-2)*(세로-2)=yellow
        if(r*2+(c-2)*2==brown
          && (r-2)*(c-2)==yellow){
            answer.push_back(r);
            answer.push_back(c);
            break;
        }
    }
    
    return answer;
}