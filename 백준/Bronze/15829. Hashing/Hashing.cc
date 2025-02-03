#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

#define R 31
#define MOD 1234567891

typedef long long ll;

ll solve(int idx, ll sum, string str) {
	if (idx == str.size()) {
		return sum % MOD;
	}

	ll r = pow(R, idx); //계수
	int si = str[idx] - 96;
	sum += r * si;
	return solve(idx + 1, sum, str);
}

int main() {
	//a=97, z=122
	int l;
	cin >> l;
	string str;
	cin >> str;

	cout << solve(0, 0, str);
}