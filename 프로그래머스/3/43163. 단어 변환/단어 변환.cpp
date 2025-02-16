#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int check(string begin, string target){
    int cnt=0; //다른 개수만큼 return
    int n = target.size();
    
    for(int j=0;j<n;j++){
        if(target[j]!=begin[j]) {
            cnt++;
        }
    }
    
    return cnt;
}

int ans = 51;

//dfs
void solve(int count, int idx, string begin, string target, vector<string> words, vector<bool>& visited){
    if(check(begin,target)==0){
        ans=min(ans,count);
        return;
    }
    
    if(idx!=-1) visited[idx]=true;
    
    int n=words.size();
    for(int i=0;i<n;i++){
        //begin이랑 한글자 차이나는 단어 탐색
        if(!visited[i] && check(begin, words[i])==1){
            solve(count+1, i, words[i], target, words, visited);
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    
    for(int i=0;i<words.size();i++){
        if(words[i]==target){
            //함수 실행
            vector<bool> visited(words.size(),false);
            solve(0, -1, begin, target, words, visited);
            
            if(ans==51) return answer;
            else answer = ans;
            return answer;
        }
    }
    
    return answer;
}