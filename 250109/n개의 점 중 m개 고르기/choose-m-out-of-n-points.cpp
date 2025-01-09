#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

vector<ll> dist;

ll calcalc(int ax, int ay, int bx, int by) {
	ll x = abs(ax - bx);
	ll y = abs(ay - by);
	x = pow(x, 2);
	y = pow(y, 2);

	return x + y;
}

void calc(vector<pair<int, int>> selectVec) {
	int m = selectVec.size();

	//m개중 가장 거리가 먼 2개 선택하기
	ll large = 0;
	for (int i = 0; i < m; i++) {
		for (int j = i + 1; j < m; j++) {
			int ax = selectVec[i].first;
			int ay = selectVec[i].second;
			int bx = selectVec[j].first;
			int by = selectVec[j].second;

			ll dis = calcalc(ax, ay, bx, by);

			if (dis > large) large = dis;
		}
	}

	if (large != 0) {//m개중 가장 거리가 먼
		dist.push_back(large);
	}
}

void solve(int cnt, int m, int idx, const vector<pair<int, int>>& vec, vector<pair<int, int>>& selectVec) {
	if (cnt == m) { //m개를 모두 선택한 경우2
		calc(selectVec);
		return;
	}

	int n = vec.size();

	vector<pair<int, int>>& curSelectVec = selectVec;
	//n개중 m개 선택하기
	for (int i = idx; i < n; i++) {
		curSelectVec.push_back(vec[i]);
		solve(cnt + 1, m, i+1, vec, curSelectVec);
		curSelectVec.erase(curSelectVec.end() - 1);
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
	solve(0, m, 0, vec, selectVec);
	
	sort(dist.begin(), dist.end());
	cout << dist[0];
}