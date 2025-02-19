#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

//A:65, Z:90 // Z-A:25

//알파벳과 움직이는걸 따로....

int changeChar(char ch1, char ch2){
    //현재 위치의 알파벳을 ch1->ch2로 바꾸기
    int num = abs((int)ch1-(int)ch2);
    return min(num, 26-num);
}

bool check(vector<bool> visited){
    for(int i=0;i<visited.size();i++){
        if(!visited[i]){
            return false;   //아직 완성이 안됐으면 false
        }
    }
    return true;
}

int mm=100000000;

void solve(int idx, int minnum, const string& name, vector<bool>& visited){
    int n=name.size();
    
    if(minnum>mm) return;
    
    if(check(visited)) {
        mm=min(minnum,mm);
        return;
    }
    
    //앞으로 순환
    for(int i=0;i<name.size();i++){
        if(!visited[i]){
            visited[i]=true;
            solve(i,minnum +min(n-abs(idx-i),abs(idx-i)),name,visited);
            visited[i]=false;
        }
    }
    //뒤로 순환
    for(int i=name.size()-1;i>=0;i--){
        if(!visited[i]){
            visited[i]=true;
            solve(i,minnum+min(n-abs(idx-i),abs(idx-i)),name,visited);
            visited[i]=false;
        }
    }
}

int solution(string name) {
    int answer = 0;
    vector<bool>visited(name.size(),false);
    for(int i=0;i<name.size();i++){
        if(name[i]=='A') visited[i] = true;
    }
    visited[0]=true;
    
    int abc=0;
    for(int i=0;i<name.size();i++){
        abc+=changeChar('A',name[i]); //알파벳 바꾸는~
    }
    
    solve(0,0,name,visited);
    answer = mm+abc;
    return answer;
}