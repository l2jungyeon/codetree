#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int n;

int dx[] = { 0,1 };
int dy[] = { 1,0 };

ll solve(int x, int y, const vector<vector<int>>& map, vector<vector<ll>>& dp) {
	if (x == n - 1 && y == n - 1) return 1;
	if (dp[x][y] != -1) return dp[x][y];

	int jmp = map[x][y];
	dp[x][y] = 0;

	for (int i = 0; i < 2; i++) {
		int nx = x + dx[i]* jmp;
		int ny = y + dy[i]* jmp;

		if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
			dp[x][y] = dp[x][y] + solve(nx, ny, map, dp);
		}
	}

	return dp[x][y];
}

int main() {
	cin >> n;
	vector<vector<int>> map(n,vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	vector<vector<ll>> dp(n, vector<ll>(n,-1));

	cout << solve(0, 0, map, dp);

}