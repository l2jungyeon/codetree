#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

const int dx[] = { 0,0,1,-1 };
const int dy[] = { 1,-1,0,0 };

//시간초과....

int main() {
	int n;
	cin >> n;

	vector<vector<int>> vec(n, vector<int>(n));
	vector<tuple<int, int, int>> cell(n); //값,x,y

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> vec[i][j];
			cell.push_back({ vec[i][j],i,j });
		}
	}

	sort(cell.begin(), cell.end());

	vector<vector<int>> dp(n, vector<int>(n,1));
	//작은칸부터 갱신

	for(tuple<int,int,int> t:cell){
		int curx = get<1>(t);
		int cury = get<2>(t);
		int curVal = get<0>(t);

		for (int d = 0; d < 4; d++) {
			int x = curx + dx[d];
			int y = cury + dy[d];

			if (x < n && x >= 0 && y < n && y >= 0){
				if (vec[x][y] > vec[curx][cury]) {//다음께 더 큰 경우
					dp[x][y] = max(dp[curx][cury] + 1,dp[x][y]);//다음 dp 업데이트
				}
				else if (vec[x][y] < vec[curx][cury]) {//다음께 더 작은 경우
					dp[curx][cury] = max(dp[x][y] + 1,dp[curx][cury]);
				}
			}
		}
	}
	
	int large = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (large < dp[i][j]) { large = dp[i][j]; }
		}
	}
	cout << large;

}
