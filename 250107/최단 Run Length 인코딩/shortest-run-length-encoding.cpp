#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void rightshift(string& a) {
	char ch = a[a.size() - 1];
	a = ch + a.substr(0, a.size() - 1);
}

int main() {
	string a;
	cin >> a;
	//앞이랑 뒤가 같으면 shift
	//뒤 2 앞 3 -> 뒤2와 앞3을 더해서 총 5
	int n = a.size();
	int c = n;
	while (c--) {
		char frontch = a[0];
		char backch = a[n - 1];
		if (frontch == backch) rightshift(a);
		else break;
	}

	int total = 1;
	char curChar = a[0];
	int curcnt = 1;
	for (int i = 0; i < n; i++) {
		if (curChar == a[i]) curcnt++;
		else {
			//이전의 curcnt를 total에 넣어주기
			if (curcnt == 10) total += 2;
			else total++;

			curcnt = 1;
			curChar = a[i];
			total++;
		}
	}
	if (curcnt > 10) total += 2;
	else total++;

	cout << total;
	
}
