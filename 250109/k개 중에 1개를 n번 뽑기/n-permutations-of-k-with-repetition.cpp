#include <iostream>
#include <vector>
using namespace std;

vector<int>vec;

void solve(int curNum,int k, int n) {
	if (curNum > n) {
		for (int i = 0; i < vec.size(); i++) {
			cout << vec[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < k; i++) {
		vec.push_back(i + 1);
		solve(curNum + 1, k, n);
		vec.erase(vec.begin() + (curNum-1));
	}

	return;
}

int main() {
	int k, n;
	cin >> k >> n;
	//k까지의 수를 n자리수

	solve(1, k, n);
}