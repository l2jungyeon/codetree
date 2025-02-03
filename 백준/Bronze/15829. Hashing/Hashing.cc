#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

#define R 31
#define MOD 1234567891

typedef long long ll;

string revStr(string str) {
	int n = str.size();
	string newstr = "";
	for (int i = n - 1; i >= 0; i--) {
		newstr += str[i];
	}

	return newstr;
}

//뒤에서부터 31을 계속 곱해주는느낌으로
ll solve(int idx, ll sum, string str) {
	if (idx == str.size()-1) {
		sum += str[idx] - 96;
		return sum % MOD;
	}

	int si = str[idx] - 96;
	sum = (sum + si) * R % MOD;
	return solve(idx + 1, sum, str);
}

int main() {
	//a=97, z=122
	int l;
	cin >> l;
	string str;
	cin >> str;

	str = revStr(str);
	cout << solve(0, 0, str);
}