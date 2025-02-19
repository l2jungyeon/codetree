#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(vector<int> vec: commands){
        int i = vec[0];
        int j=vec[1];
        int k=vec[2];
        
        vector<int> temp;
        for(int l=i-1;l<=j-1;l++){
            temp.push_back(array[l]);
        }
        sort(temp.begin(),temp.end());
        
        answer.push_back(temp[k-1]);
    }
    
    return answer;
}