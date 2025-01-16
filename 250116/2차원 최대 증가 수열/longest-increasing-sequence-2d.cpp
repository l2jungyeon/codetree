#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <climits>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> vec(n, vector<int>(m));
	vector<tuple<int, int, int>> cell;	//value,x,y
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> vec[i][j];
			cell.push_back({ vec[i][j],i,j });
		}
	}
	sort(cell.begin(), cell.end());	//오름차순으로 정렬(작은것부터 처리)

	vector<vector<int>> dp(n, vector<int>(m, INT_MIN));
	//i,j까지 왔을 때 밟을 수 있는 최대 칸 수
	dp[0][0] = 1;
	
	for (tuple<int, int, int> t : cell) {
		int x = get<1>(t);
		int y = get<2>(t);
		int v = get<0>(t);

		for (tuple<int, int, int> preT : cell) {
			int prex = get<1>(preT);
			int prey = get<2>(preT);
			int preV = get<0>(preT);

			if (x > prex && y > prey && preV < v) {
				dp[x][y] = max(dp[x][y], dp[prex][prey] + 1);
			}

		}
	}

	int large = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dp[i][j] > large) { large = dp[i][j]; }
		}
	}

	cout << large;
}
