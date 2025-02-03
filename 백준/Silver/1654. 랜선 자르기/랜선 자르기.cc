#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<ll> vec;

//start부터 end까지의 값을 binary search
ll solve(int n) {
	ll start = 1, end = vec[vec.size() - 1];
	ll mid = (start + end) / 2;

	while (start <= end) {
		ll cnt = 0;
		for (ll len : vec) cnt += len / mid;

		if (cnt < n) { //좌측 탐색
			end = mid - 1;
		}
		else { //우측탐색
			start = mid + 1;
		}
		mid = (start + end) / 2;

	}
	
	return mid;
}

int main() {
	int k, n;
	cin >> k >> n;

	for (int i = 0; i < k; i++) {
		ll a;
		cin >> a;
		vec.push_back(a);
	}
	sort(vec.begin(), vec.end());

	cout << solve(n);
}