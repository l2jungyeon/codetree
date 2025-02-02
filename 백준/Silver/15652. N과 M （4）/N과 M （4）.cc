#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void solve(int n, int m, int idx, vector<int>& vec) {
	if (idx == m) {
		for (int i : vec) {
			cout << i << " ";
		}
		cout << "\n";
		return;
	}

	int prevNum=1;
	if (idx > 0)prevNum = vec[idx - 1];
	for (int i = prevNum; i <= n; i++) {
		vec[idx] = i;
		solve(n, m, idx + 1, vec);
	}
}

int main() {
	int n, m;
	cin >> n >> m; //숫자 n까지, m개의 원소로 이루어진 수열

	vector<int>vec(m, 0);
	solve(n, m,0,vec);

}