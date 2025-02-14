#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    sort(lost.begin(),lost.end());
    sort(reserve.begin(),reserve.end());
    
    vector<int> throwvec;
    vector<bool> visited(lost.size(),false); //체육복을 빌리면 true

    for(int i=0;i<lost.size();i++){
        for(int j=0;j<reserve.size();j++){
            if(lost[i]==reserve[j]){
                visited[i]=true;
                throwvec.push_back(lost[i]);
                reserve.erase(reserve.begin()+j);
            }
        }
    }
        
    //lost를 앞에서부터 탐색하면서 앞or뒷사람한테 빌리기
    for(int i=0;i<lost.size();i++){
        if(visited[i]==true) continue;
        int curp = lost[i];
        
        for(int j=0;j<reserve.size();j++){
            int sidep = reserve[j];
            if(sidep==curp-1){
                visited[i] = true;
                reserve.erase(reserve.begin()+j);
                break;
            }
            else if(sidep==curp+1){
                visited[i] = true;
                reserve.erase(reserve.begin()+j);
                break;
            }
        }
        
    }
    
    int cnt=0;
    for(bool b:visited){
        if(b==false) cnt++;
    }
    answer = n-cnt;
    
    return answer;
}