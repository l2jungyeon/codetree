#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> minvec;

void solve(int row, vector<vector<int>> vec, vector<int>& ans, vector<bool>& col) {
	int n = vec.size();
	if (row == n) {
		int small = 100001;
		for (int s : ans) {
			if (s < small) small = s;
		}
		minvec.push_back(small);
	}

	//각 행마다 한개씩 고를거임
	//고를때 열이 또 겹치면 안됨
	for (int i = 0; i < n; i++) {
		if (!col[i]) {
			col[i] = true;
			ans.push_back(vec[row][i]);
			solve(row + 1, vec, ans, col);
			ans.pop_back();
			col[i] = false;
		}
	}
}


int main() {
	int n;
	cin >> n;

	vector<vector<int>> vec(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> vec[i][j];
		}
	}
	vector<bool> col(n, false);
	vector<int> ans;
	solve(0, vec, ans, col);

	sort(minvec.begin(), minvec.end());
	cout << minvec[minvec.size() - 1];
}