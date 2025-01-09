#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

vector<int> dist;

int calcalc(int ax, int ay, int bx, int by) {
	ll x = abs(ax - bx);
	ll y = abs(ay - by);
	x = pow(x, 2);
	y = pow(y, 2);
	return x + y;
}

void calc(vector<pair<int, int>> selectVec) {
	int m = selectVec.size();

	//m개중 가장 거리가 먼 2개 선택하기
	int large = 0;
	for (int i = 0; i < m; i++) {
		for (int j = i + 1; j < m; j++) {
			int ax = selectVec[i].first;
			int ay = selectVec[i].second;
			int bx = selectVec[j].first;
			int by = selectVec[j].second;

			int dis = calcalc(ax, ay, bx, by);

			if (dis == 0) continue;
			if (dis > large) large = dis;
		}
	}

	if (large != 0) {
		dist.push_back(large);
	}
}

void solve(int cnt, int m, const vector<pair<int, int>>& vec, vector<pair<int, int>>& selectVec) {
	if (cnt == m) {
		calc(selectVec);
		return;
	}

	int n = vec.size();

	//n개중 m개 선택하기
	for (int i = 0; i < n; i++) {
		selectVec.push_back(vec[i]);
		solve(cnt + 1, m, vec, selectVec);
		selectVec.erase(selectVec.end()-1);
	}

	return;
}

int main() {
	int n, m;
	//n개의 점들중 m개 고르기
	cin >> n >> m;

	vector<pair<int, int>> vec(n);
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		vec[i] = { a,b };
	}

	vector<pair<int, int>> selectVec;
	solve(0, m, vec, selectVec);
	
	sort(dist.begin(), dist.end());
	cout << dist[0];
}