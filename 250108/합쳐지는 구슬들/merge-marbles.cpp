#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

//상,하,좌,우
const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,-1,1 };

bool compare(tuple<int, int, int> t1, tuple<int, int, int> t2) {
	return get<2>(t1) > get<2>(t2);
}

void move(int n, vector<tuple<int, int, int>>& roll, vector<tuple<int, int, int>>& numDirWeight) {
	vector<pair<int,int>> samexy; //번호 int와 int가 같은 위치에잇음
	int m = roll.size();
	for (int i = 0; i < m; i++) { //각 구슬에 대해서
		int curnum = get<0>(roll[i]);
		int curx = get<1>(roll[i]);
		int cury = get<2>(roll[i]);
		int dirIdx = get<1>(numDirWeight[i]);

		//방향 바꾸기
		if (cury == 0 && dirIdx == 2)  
			get<1>(numDirWeight[i]) = 3;
		else if (cury == n - 1 && dirIdx == 3)  
			get<1>(numDirWeight[i]) = 2;
		else if (curx == 0 && dirIdx == 0) 
			get<1>(numDirWeight[i]) = 1;
		else if (curx == n - 1 && dirIdx == 1)  
			get<1>(numDirWeight[i]) = 0;
		else { //움직이기
			get<1>(roll[i]) = curx + dx[dirIdx];
			get<2>(roll[i]) = cury + dy[dirIdx];
		}

		//같은 위치에 있는 구슬이 있나 확인
		for (int j = 0; j < i; j++) {
			if (get<1>(roll[j]) == get<1>(roll[i]) 
				&& get<2>(roll[j]) == get<2>(roll[i])) {
				samexy.push_back({ curnum, get<0>(roll[j]) });
			}
		}
	}

	//움직인 후 같은 위치에 있는 구슬 처리
	int k = samexy.size();
	for (int i = 0; i < k; i++) {
		int first = samexy[i].first;
		int sec = samexy[i].second;

		int larger;
		int smaller;
		for (int i = 0; i < m; i++) { //번호 찾기
			if (first == get<0>(numDirWeight[i])) {
				first = i;
			}
			if (sec == get<0>(numDirWeight[i])) {
				sec = i;
			}
		}

		if (first > sec) {
			larger = first; smaller = sec;
		}
		else {
			larger = sec; smaller = first;
		}

		roll.erase(roll.begin() + smaller);
		get<2>(numDirWeight[larger]) += get<2>(numDirWeight[smaller]);
		numDirWeight.erase(numDirWeight.begin() + smaller);
	}

}

int main() {
	int n, m, t;
	cin >> n >> m >> t;

	vector<tuple<int, int, int>> roll(m);
	vector< tuple<int, int, int>> numDirWeight(m);

	for (int i = 0; i < m; i++) {
		char ch;
		int a, b;
		int w;
		int c;
		cin >> a >> b >> ch >> w;

		tuple<int, int, int> t = { i+1 ,a-1,b-1 };
		roll[i] = t;

		if (ch == 'U') c = 0;
		else if(ch=='D') c = 1;
		else if (ch == 'L')c = 2;
		else if (ch == 'R')c = 3;

		tuple<int, int, int> ft = { i + 1 ,c,w };
		numDirWeight[i] = ft;
	}

	while (t--) {
		move(n, roll, numDirWeight);
	}

	//남아있는 구슬의 수와 가장 무거운 구슬의 무게 출력
	sort(numDirWeight.begin(), numDirWeight.end(), compare);
	cout << numDirWeight.size() << " " << get<2>(numDirWeight[0]);
}

//  9l 10u
// 7u 