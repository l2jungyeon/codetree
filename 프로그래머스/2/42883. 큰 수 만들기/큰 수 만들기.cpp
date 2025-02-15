#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//못풀음 ㅜㅜ
string solution(string number, int k) {
    string answer = "";
    
    while(k!=0){
        bool istrue=false;
        
        //앞에서부터 두개씩 비교
        //현재 숫자보다 이전 숫자가 작으면 이전숫자 삭제
        for(int i=1;i<number.size();i++){
            if(k!=0 && number[i-1]-'0' < number[i]-'0'){
                istrue=true;
                number.erase(number.begin()+i-1);
                i=0;
                k--;
            }
        }
        
        //삭제할게 없는 경우
        if(!istrue){
            //뒤에서부터 k개만큼 삭제
            for(int i=0;i<k;i++) number.erase(number.size() - 1);
            k=0;
        }
        
    }
    
    answer = number;
    return answer;
}