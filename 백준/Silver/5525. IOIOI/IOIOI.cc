#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string pfunc(int n) {
	string p="";
	n *= 2;
	while (n--) {
		if (n % 2 == 1)p += "I";
		else p += "O";
	}

	p += "I";
	return p;
}

int main() {
	int n, s;
	cin >> n;
	cin >> s;
	string str;
	cin >> str;

	string p = pfunc(n);

	int idx = 0;
	int cnt = 0;
	while (true) {
		string substr = str.substr(idx, str.size());
		int subidx = substr.find(p);

		if (subidx == -1)break;
		else if (subidx + idx < str.size())cnt++;

		idx += subidx + 2;
	}

	cout << cnt;
}