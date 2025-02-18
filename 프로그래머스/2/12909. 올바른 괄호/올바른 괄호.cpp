#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    
    stack<char> stack;
    for(int i=0;i<s.size();i++){
        if(s[i]=='(') stack.push('(');
        else if(s[i]==')'){
            if(stack.size()==0) {
                answer=false;
                break;
            }
            stack.pop();
        }
    }
    
    if(stack.size()!=0) answer = false;
    
    return answer;
}