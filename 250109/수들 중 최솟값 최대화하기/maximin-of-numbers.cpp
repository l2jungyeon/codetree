#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int calc(const vector<vector<int>>& vec, vector<pair<int, int>> pairVec) {
	int smaller = INT16_MAX;
	for (pair<int, int> p : pairVec) {
		int r = p.first;
		int c = p.second;
		int num = vec[r][c];
		if (smaller > num) smaller = num;
	}

	return smaller;
}

vector<int> minnumvec;

void solve(int cnt, const vector<vector<int>>& vec, vector<bool>& row, vector<bool>& col, vector<pair<int,int>>& pairVec) {
	int n = vec.size();
	if (cnt == n) {
		minnumvec.push_back(calc(vec, pairVec));
		return;
	}
	int currow, curcol;

	for (int i = 0; i < n; i++) {
		if (row[i] == false) {
			row[i] = true;
			currow = i; break;
		}
	}
	for (int i = 0; i < n; i++) {
		if (col[i] == false) {
			col[i] = true;
			curcol = i; 

			pairVec.push_back({ currow,curcol });
			solve(cnt + 1, vec, row, col, pairVec);
			pairVec.erase(pairVec.end() - 1);
			row[currow] = false;
			col[curcol] = false;
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

	vector<bool> row(n, false);
	vector<bool> col(n, false);
	vector<pair<int, int>> pairVec;
	solve(0, vec, row, col, pairVec);

	sort(minnumvec.begin(), minnumvec.end());
	cout << minnumvec[minnumvec.size()-1];

}