#include <string>
#include <vector>
#include <cmath>
#include <iostream>
typedef long long ll;
using namespace std;

ll solution(int n, vector<int> times) {
    ll answer = 0;
    
    //걸리는 시간동안 몇명을 처리할 수 있는지
    ll start = 1;
    ll end = pow(10,18);
    // ll end = 90;
    ll middle;
    
    while(start<=end){
        middle=(start+end)/2;
        // cout <<middle<<endl;
        ll num = 0;
        for(int i=0;i<times.size();i++){
            num += middle/(ll)times[i];
        }
        
        //줄여야함
        if(num>=n) {
            answer = middle;
            end = middle-1;
        }
        else start = middle+1;
    }
    
    return answer;
}