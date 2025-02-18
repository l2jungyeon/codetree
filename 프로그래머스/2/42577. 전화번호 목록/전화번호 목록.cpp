#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    int n=phone_book.size();
    sort(phone_book.begin(),phone_book.end());
    
    //i가 j의 접두사인가?
    bool flag=true;
    for(int i=0;i<n-1;i++){
        if(phone_book[i+1].find(phone_book[i])==0){
            flag = false;
            break;
        }
    }
    
    answer = flag;
    return answer;
//     어떤 번호가 다른 번호의 접두어인 경우가 있으면 false를 그렇지 않으면 true를 return
}