#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool compare(string str1, string str2) {
    if (str1.size() == str2.size()) {
        //숫자만 더하기
        int sum1 = 0;
        int sum2 = 0;
        for (int i = 0; i < str1.size(); i++) {
            if (str1[i] - '0' >= 0 && str1[i] - '0' <= 9)
                sum1 += str1[i] - '0';
            if (str2[i] - '0' >= 0 && str2[i] - '0' <= 9) 
                sum2 += str2[i] - '0';
        }

        if (sum1 == sum2) {
            return str1  < str2; //사전순으로 비교
        }
        return sum1 < sum2; //더 작은 합
    }
    return str1.size() < str2.size();//더 짧은 것
}

int main() {
    int n;
    cin >> n;
    // 우선순위
    //짧은것, 숫자인것만 저했을 때 작은것, 사전순

    vector<string> vec(n);
    for (int i = 0; i < n; i++) cin >> vec[i];

    sort(vec.begin(), vec.end(), compare);
    for (int i = 0; i < n; i++)    cout << vec[i] << "\n";

    
}