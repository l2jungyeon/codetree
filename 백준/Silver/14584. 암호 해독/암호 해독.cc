#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;

	int n;
	cin >> n;
	vector<string> dict(n);
	for (int i = 0; i < n; i++) {
		cin >> dict[i];
	}

	//해독한 문장에서 사전에 나오는 단어가 반드시 하나 이상 등장
	//a-z: 97-122

	for (int i = 1; i <= 26; i++) { //한칸씩 뒤로 미루기
		for (int j = 0; j < str.size(); j++) {//하나씩 더해보기
			char c = str[j];
			c = c + 1;
			if (c == 123) {
				c = 97;
			}
			str[j] = c;
		}

		for (int d = 0; d < n; d++) {
			//사전에 있는 단어랑 하나씩 대조해보기
			if (str.find(dict[d]) != string::npos) {
				cout << str;
				return 0;
			}
		}
	}
	
	//cout << str;
}