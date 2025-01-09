#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int calc(const vector<vector<int>>& vec, const vector<pair<int, int>>& pairVec) {
	int smaller = 100001;
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

	vector<bool> rowvec = row;
	vector<bool> colvec = col;
	vector<pair<int, int>> pair = pairVec;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!rowvec[i] && !colvec[j]) {
				currow = i; curcol = j;
				rowvec[currow] = true;
				colvec[curcol] = true;
				pair.push_back({ currow,curcol });
				
				solve(cnt + 1, vec, rowvec, colvec, pair);

				pair.erase(pair.end() - 1);
				rowvec[currow] = false;
				colvec[curcol] = false;
			}
		}
	}
	return;
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