#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    int prevNum=arr[0];
    answer.push_back(arr[0]);
    for(int i=0;i<arr.size();i++){
        if(prevNum==arr[i]) continue;
        else{
            answer.push_back(arr[i]);
            prevNum=arr[i];
        }
    }

    return answer;
}