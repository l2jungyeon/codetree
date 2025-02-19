#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//못풂 ㅠㅠ

bool compare(string s1, string s2){
    return s1+s2>s2+s1;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> vec;
    
    for(int i=0;i<numbers.size();i++){
        vec.push_back(to_string(numbers[i]));        
    }
    
    sort(vec.begin(),vec.end(),compare);
    
    for(int i=0;i<numbers.size();i++){
        answer+=vec[i];
    }
    
    if(answer[0]=='0') answer = "0";
    return answer;
}