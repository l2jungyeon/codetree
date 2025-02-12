#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    unordered_map<string,string> map; //아이디-닉네임
    
    //record를 한번 순회하면서 마지막 userid와 닉네임을 map에 저장하기
    for(int i=0;i<record.size();i++){
        vector<string> recvec;
        stringstream sstream(record[i]);
        string word;
        
        while(getline(sstream, word, ' ')){
            recvec.push_back(word);
        }
        
        if(record[i].front()=='E'){ //enter
            map[recvec[1]]=recvec[2];
        }
        else if(record[i].front()=='C'){ //change
            map[recvec[1]]=recvec[2];
        }
    }
    
    //record를 순회하면서 answer에 집어넣기
    for(int i=0;i<record.size();i++){
        vector<string> recvec;
        stringstream sstream(record[i]);
        string word;
        
        while(getline(sstream, word, ' ')){
            recvec.push_back(word); //[1]:userid, [2]:닉네임
        }
        
        if(record[i].front()=='E'){ //enter
            string str = map[recvec[1]];
            str+="님이 들어왔습니다.";
            answer.push_back(str);
        }
        else if(record[i].front()=='L'){ //leave
            string str = map[recvec[1]];
            str+="님이 나갔습니다.";
            answer.push_back(str);
        }
    }
    
    return answer;    
}