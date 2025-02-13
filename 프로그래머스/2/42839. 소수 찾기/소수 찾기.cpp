#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <unordered_map>

using namespace std;

int n;

bool check(vector<int> vec){
    int num=0;
    for(int i=0;i<vec.size();i++){
        num+=vec[vec.size()-i-1]*pow(10,i);
    }
    
    if(num<=1) return false;
    
    for(int i=2;i<=sqrt(num);i++){
        if(num%i==0) return false;
    }
    return true;
}

vector<int> ans;
unordered_map<int,int> map;

void solve(vector<int> ans, const vector<int>& vec, vector<bool> visited){
    //소수인지 검사
    if(check(ans)){
        //중복 검사
        int num=0;
        for(int i=0;i<ans.size();i++){
            num+=ans[ans.size()-i-1]*pow(10,i);
        }   
        
        if(map.find(num)==map.end()){ //기존에 없다면
            map[num]=1;
            cout << num<<" ";
        }
    }
    
    if(ans.size()==n){
        return;
    }
    
    for(int i=0;i<vec.size();i++){
        if(!visited[i]){
            ans.push_back(vec[i]);
            visited[i]=true;
            
            solve(ans,vec,visited);
            
            ans.erase(ans.end()-1);
            visited[i]=false;
        }
    }
}

int solution(string numbers) {
    int answer = 0;
    
    vector<int> vec;
    for(int i=0;i<numbers.size();i++){
        vec.push_back(numbers[i]-'0');
        // cout << vec[i]<<" ";
    }
    n = vec.size();
    vector<bool> visited(n,false);
    
    int ansnum=0;
    solve(ans, vec, visited);
    
    answer = map.size();
    
    return answer;
}