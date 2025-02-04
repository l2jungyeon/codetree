#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> sumvec;

int main() {
	cin >> n;
	vector<int> vec(n);
	for (int i = 0; i < n; i++)cin >> vec[i];

	sort(vec.begin(), vec.end(),greater<int>());
	for (int i = 0; i < n-2; i++) {
		if (vec[i + 2] + vec[i + 1] > vec[i]) {
			sumvec.push_back(vec[i] + vec[i + 2] + vec[i + 1]);
			break;
		}
	}

	if (sumvec.size() == 0) cout << "-1";
	else {
		cout << sumvec[sumvec.size() - 1];
	}
}