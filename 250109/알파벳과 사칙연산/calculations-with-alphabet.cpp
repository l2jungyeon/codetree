#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int calc(vector<char> str1, vector<char> str2, unordered_map<char,int> dict) {
    int prevNum = dict[str1[0]];
    char curCal;
    for (int i = 1; i < str1.size() + str2.size(); i++) {
        if (i % 2 == 0) {
            int curNum = dict[str1[i / 2]];
            if (curCal == '*') prevNum = prevNum * curNum;
            if (curCal == '+') prevNum = prevNum + curNum;
            if (curCal == '-') prevNum = prevNum - curNum;

        }
        else {
            curCal = str2[i / 2];
        }
    }

    return prevNum;
}

int maxnum = 0;

void solve(vector<char> str1, vector<char> str2, unordered_map<char, int>& dict, int idx) {
    if (idx == str1.size()) {
        int c = calc(str1, str2, dict);
        if (maxnum < c) maxnum = c;
        return;
    }

    unordered_map<char, int> newdict = dict;
    //이전 재귀에서 이미 할당한경우 그대로 적용
    if (newdict.find(str1[idx])==newdict.end()) { //할당이 안되어있다면 1부터 4까지 다 넣어보기
        for (int i = 1; i <= 4; i++) { 
            char curCh = str1[idx];
            newdict[curCh] = i;
            solve(str1, str2, newdict, idx + 1);

        }
    }
    else {
        solve(str1, str2, dict, idx + 1);
    }
    return;
}

int main() {
    string str;
    cin >> str;

    vector<char> str1;  //알파벳, abcdef
    vector<char> str2;  //기호, +-*
    for (int i = 0; i < str.size(); i++) {
        if (i % 2 == 0) str1.push_back(str[i]);
        else str2.push_back(str[i]);
    }

    unordered_map<char, int> dict;
    solve(str1, str2, dict, 0);
    cout << maxnum;
}