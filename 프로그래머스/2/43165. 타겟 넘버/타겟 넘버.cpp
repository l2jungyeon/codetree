#include <string>
#include <vector>

using namespace std;

int ans=0;

void solve(int num, int idx, const vector<int>& numbers, int target){
    if(idx>=numbers.size()){
        if(num==target) ans++;
        return;
    }
    
    for(int i=0;i<2;i++){   //더하기 또는 빼기
        if(i==0) solve(num+numbers[idx], idx+1, numbers,target);
        else solve(num-numbers[idx], idx+1, numbers, target);
    }
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    solve(0,0,numbers,target);
    answer = ans;
    
    return answer;
}