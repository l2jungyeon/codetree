#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int solve(vector<vector<int>> vec, int x, int y, int k, int l) {
	int dx; int dy;
	int n = vec.size();//세로
	int m = vec[0].size();//가로

	if (vec[x][y] == 0) return -1;

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < l; j++) {
			if (vec[x+i][y+j]==1) {
				dx = i+1;
				dy = j+1;
			}
			else {
				return -1;
			}
		}
	}

	return dx * dy;
}

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> vec(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> vec[i][j];
			if (vec[i][j] > 0) vec[i][j] = 1;
			else vec[i][j] = 0;
		}
	}

	int large = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 1; k <= n-i; k++) {	//가로길이
				for (int l = 1; l <= m-j; l++) {//세로길이
					int res = solve(vec, i, j, k, l);
					if (res > large) large = res;
				}
			}
		}
	}

	cout << large;

}
