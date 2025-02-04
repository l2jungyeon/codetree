#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string key;
	cin >> key;
	int n = key.size();

	string str;
	cin >> str;
	int m = str.size();

	int row = m/n+1;
	int col = n;

	string sortkey = key;
	sort(sortkey.begin(), sortkey.end());
	
	vector<vector<char>> map_reverse(col, vector<char>(row));

	for (int i = 0; i < n; i++) {
		map_reverse[i][0] = sortkey[i];
	}

	for (int i = 0; i < col; i++) {
		for (int j = 1; j < row; j++) {
			map_reverse[i][j] = str[j-1 + (i * (m/n))];
		}
	}

	vector<bool> visited(n, false); //sortkey의 idx
   	vector<vector<char>> map(row,vector<char>(col));

	for (int i = 0; i < col; i++) {
		int idx=0;
		//번호 찾기
		char ch = key[i];
		for (int j = 0; j < col; j++) {
			if (map_reverse[j][0] == ch && !visited[j]) {
				idx = j;
				visited[j] = true;
				break;
			}
		}

		for (int j = 1; j < row; j++) {
			map[j][i] =  map_reverse[idx][j];
		}
	}

	for (int j = 1; j < row; j++) {
		for (int i = 0; i < col; i++) {
			cout << map[j][i];
		}
	}
}
