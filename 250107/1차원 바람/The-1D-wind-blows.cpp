#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void leftblow(vector<int>& rowvec) { //'L'인경우
	//오른쪽으로 shift
	int size = rowvec.size();
	int temp = rowvec[size - 1];

	for (int i = size - 1; i > 0; i--) {
		rowvec[i] = rowvec[i - 1];
	}
	rowvec[0] = temp;
}

void rightblow(vector<int>& rowvec) { //'R'인경우
	//왼쪽으로 shift
	int size = rowvec.size();
	int temp = rowvec[0];

	for (int i = 1; i < size; i++) {
		rowvec[i-1] = rowvec[i];
	}
	rowvec[size-1] = temp;
}

bool checkrow(vector<int> vec1, vector<int> vec2) {
	bool torf = false;

	for (int i = 0; i < vec1.size(); i++) {
		if (vec1[i] == vec2[i]) {
			torf = true;
			break;
		}
	}

	return torf;
}

int main() {
	int n, m, q;
	cin >> n >> m >> q;

	vector<vector<int>> vec(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> vec[i][j];
		}
	}

	while (q--) {
		int r;
		char d;
		cin >> r >> d;

		r -= 1;
		bool isLeft = (d == 'L' ? true : false);
		if (isLeft) leftblow(vec[r]);
		else rightblow(vec[r]);
		isLeft = !isLeft;

		int uprow = r - 1;
		int currow = r;
		while (uprow >= 0) { //up
			if (checkrow(vec[currow], vec[uprow])) {
				if (isLeft) leftblow(vec[uprow]);
				else rightblow(vec[uprow]);
				isLeft = !isLeft;
				uprow--; currow--;
			}
			else {
				uprow = -1;
			}
		}

		isLeft = (d == 'L' ? false : true);
		int downrow = r + 1;
		currow = r;
		while (downrow < n) { //down
			if (checkrow(vec[currow], vec[downrow])) {
				if (isLeft) leftblow(vec[downrow]);
				else rightblow(vec[downrow]);
				isLeft = !isLeft;
				downrow++; currow++;
			}
			else {
				downrow = n;
			}
		}
		
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << vec[i][j] << " ";
		}
		cout << "\n";
	}
	
}
