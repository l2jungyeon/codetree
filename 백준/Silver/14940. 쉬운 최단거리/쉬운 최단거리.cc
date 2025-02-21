#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };

vector<vector<int>> bfs(int x, int y, vector<vector<int>> vec) {
    //각 지점에서 목표지점까지의 거리
    int n = vec.size();
    int m = vec[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    vector<vector<bool>> visited(n, vector<bool>(m));

    queue<tuple<int, int, int>> q; //거리, x, y
    q.push({ 0,x,y });

    while (!q.empty()) {
        int dist = get<0>(q.front());
        int curx = get<1>(q.front());
        int cury = get<2>(q.front());
        q.pop();

        if (visited[curx][cury]) continue;
        visited[curx][cury] = true;

        dp[curx][cury] = dist;

        for (int i = 0; i < 4; i++) {
            int nx = curx + dx[i];
            int ny = cury + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m
                && !visited[nx][ny] && vec[nx][ny] != 0) {
                q.push({ dist + 1,nx,ny });
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j] == false && vec[i][j] == 1) {
                dp[i][j] = -1;
            }
        }
    }

    return dp;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> vec(n, vector<int>(m));
    int x, y;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> vec[i][j];
            //0은 못가는땅, 1은 갈수잇는, 2는 목표
            if (vec[i][j] == 2) {
                x = i; y = j;
            }
        }
    }

    vector<vector<int>> dp = bfs(x, y, vec);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
}