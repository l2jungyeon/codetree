#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool checkRight(const vector<vector<int>>& vec, int x, int y) {
	return y + 1 >= vec.size() || vec[x][y] == -1 || vec[x][y] != vec[x][y + 1];
}

bool checkDown(const vector<vector<int>>& vec, int x, int y) {
	return x + 1 >= vec.size() || vec[x][y] == -1 || vec[x][y] != vec[x + 1][y];
}

//쌍의 개수 세는 함수
int countpair(const vector<vector<int>>& vec) {
	int n = vec.size();
	int total = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			//오른쪽과 아래쪽만 확인.
			if (!checkDown(vec, i, j)) total++;
			if (!checkRight(vec, i, j)) total++;
		}
	}

	return total;
}

//폭탄이 터진 후의 배열을 반환하는 함수
void bomb(vector<vector<int>>& vec, int x, int y) {
	int num = vec[x][y];
	int size = vec.size();

	for (int i = 0; i < num; i++) {//터진부분을 -1로 만들기
		if (x + i < size) vec[x + i][y] = -1;
		if (x - i >= 0) vec[x - i][y] = -1;
		if (y + i < size)vec[x][y + i] = -1;
		if (y - i >= 0) vec[x][y - i] = -1;
	}

	//-1인부분을 없는걸로 취급 후 새로운 배열 반환
	for (int i = 0; i < size; i++) {//각 열에 대해서
		vector<int> temp(0);

		for (int j = 0; j < size; j++) {
			if (vec[j][i] != -1) {
				temp.push_back(vec[j][i]);
			}
		}

		int tsize = temp.size();
		for (int j = 0; j < size; j++) {
			if (tsize - j - 1 >= 0) { vec[size - 1 - j][i] = temp[tsize - 1 - j]; }
			else vec[size - 1 - j][i] = -1;
		}
	}
}

int main() {
	int n;
	cin >> n;

	vector<vector<int>> vec(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> vec[i][j];			//1~100
		}
	}

	int large = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			vector<vector<int>> newvec = vec;
			bomb(newvec, i, j);
			int total = countpair(newvec);
			if (large < total) large = total;
		}
	}

	cout << large;
}
