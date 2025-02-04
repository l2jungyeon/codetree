#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

typedef long long ll;

int n, s;	int cnt = 0;

//dp가 아니라 "백트래킹"으로 풀어야함

void solve(int idx, int sum, vector<ll> vec) {
	if (idx==n) {
		if (sum == s) cnt++;
		return;
	}

	solve(idx + 1, sum + vec[idx], vec); //선택하는 경우
	solve(idx + 1, sum, vec);//선택하지 않는 경우
}

int main() {
	cin >> n >> s;

	vector<ll> vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}

	solve(0, 0, vec);
	if (s == 0)cnt--;
	cout << cnt;
}
