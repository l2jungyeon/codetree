#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 200000001

int main() {
	int n;
	cin >> n;

	vector<int> vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}
	//세 수의 합(서로 같아도 됨)이 vec안에 있어야 함

	sort(vec.begin(), vec.end());

	vector<bool>dp(MAX,false);
	//두 원소의 합
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if(vec[i] + vec[j]< MAX) dp[vec[i] + vec[j]] = true;
		}
	}

	for (int i = n-1; i >=0; i--) {
		for (int j = n - 2; j >= 0; j--) {
			if (vec[i] - vec[j]>=0 && dp[vec[i] - vec[j]]) {
				cout << vec[i];
				return 0;
			}
		}
	}
}