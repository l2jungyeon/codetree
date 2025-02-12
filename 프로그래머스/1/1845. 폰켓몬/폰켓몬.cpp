#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    //포켓몬 종류 수
    int pokN=1;
    sort(nums.begin(),nums.end());
    
    int prevNum = nums[0];
    for(int i=0;i<nums.size();i++){
        if(prevNum!=nums[i]){
            pokN++;
            prevNum = nums[i];
        }
    }
    
    
    answer = nums.size()/2;
    if(answer > pokN) answer = pokN;
    
    return answer;
}