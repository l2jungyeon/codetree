#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    for(int i=0;i<participant.size();i++){
        if(i==completion.size()){
            answer = participant[i];break;
        }
        else if(participant[i]!=completion[i]){
            answer = participant[i];break;
        }
    }
    
    return answer;
}