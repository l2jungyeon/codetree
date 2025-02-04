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

	sort(vec.begin(), vec.end());
	for (int i = 2; i < n; i++) {
		if (vec[i - 2] + vec[i - 1] > vec[i]) {
			sumvec.push_back(vec[i] + vec[i - 1] + vec[i - 2]);
		}
	}

	if (sumvec.size() == 0) cout << "-1";
	else {
		cout << sumvec[sumvec.size() - 1];
	}
}