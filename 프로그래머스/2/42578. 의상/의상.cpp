#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

//  서로 다른 옷의 조합의 수를 return
int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    unordered_map<string, int> map;
    for(int i=0;i<clothes.size();i++){
        if(map.find(clothes[i][1])==map.end()){
            map[clothes[i][1]]=1;
        }
        else map[clothes[i][1]]+=1;
    }
    
    for(auto& p:map){
        answer*=(p.second+1);
    }
    
    return answer-1;
}