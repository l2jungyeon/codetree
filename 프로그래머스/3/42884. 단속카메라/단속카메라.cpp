#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> r1, vector<int> r2){
    return r1[1]<r2[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 1;
    
    sort(routes.begin(),routes.end(),compare);
    
    int prevEnd=routes[0][1];
    
    for(int i=1;i<routes.size();i++){
        int st = routes[i][0];
        int en = routes[i][1];
        
        if(st<=prevEnd){ //겹치면
            continue;
        }
        else{//안겹치면
            answer++;
            prevEnd=en;
        }
    }
    
    return answer;
}