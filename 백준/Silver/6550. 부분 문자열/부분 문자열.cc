#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	string s;
	string t;

	while (cin >> s >> t) {
		//s가 t의 부분문자열?
		int sIdx = 0;
		for (int i = 0; i < t.size(); i++) {
			if (t[i] == s[sIdx]) {
				sIdx++;
			}
		}

		if (sIdx == s.size()) cout << "Yes";
		else cout << "No";
		cout << "\n";
	}
}