#include <iostream>
#include <vector>
using namespace std;

//상,하,좌,우
const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,-1,1 };

//1인경우 하<->좌, 상<->우	더해서 3
//2인경우 상<->좌, 하<->우	빼면 2
//0123

int solve(vector<vector<int>> vec, int k, int idx) {
	int n = vec.size();
	int curIdx = idx;
	int total = 1;

	/*현재 위치 업데이트*/
	int curx, cury;
	if (curIdx == 0) {//상
		cury = k; 
		curx = n - 1;
	}
	else if (curIdx == 1) {//하
		cury = k; 
		curx = 0;
	}
	else if (curIdx == 2) {//좌
		cury = n - 1; 
		curx = k;
	}
	else if (curIdx == 3) {//우
		cury = 0; 
		curx = k;
	}

	while (curx >= 0 && curx < n && cury >= 0 && cury < n) {	//격자 안에 있을 때
		if (vec[curx][cury] == 0) {
			curx += dx[curIdx];
			cury += dy[curIdx];
			total++;
		}
		else if (vec[curx][cury] == 1) {
			curIdx = 3 - curIdx;
			curx += dx[curIdx];
			cury += dy[curIdx];	
			total++;

		}
		else if (vec[curx][cury] == 2) {
			curIdx = (2 + curIdx) % 4;
			curx += dx[curIdx];
			cury += dy[curIdx];
			total++;
		}
	}

	return total;
}

int main() {
	int n;
	cin >> n;

	vector<vector<int>> vec(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> vec[i][j];			//0,1,2
		}
	}

	int maxTime = 1;	//들어가는 시간
	for (int j = 0; j < 4; j++) {//상하좌우
		for (int i = 0; i < n; i++) {	//모서리
			int time = solve(vec, i, j);
			if (maxTime < time) maxTime = time;
		}
	}

	cout << maxTime;
}
