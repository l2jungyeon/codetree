// 안전한 영역의 최대 개수를 계산

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int solve(int d, vector<vector<int>> map) {
    //높이가 d 이하인 지역은 물에 잠김
    int n = map.size();
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    queue<pair<int, int>> q;

    //물에 잠긴 지역을 모두 visited로 처리
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] <= d) visited[i][j] = true;
        }
    }

    int ans = 0;
    //bfs
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //bfs 탈출시
            if (visited[i][j]) continue;
            q.push({ i,j });

            while (!q.empty()) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                if (visited[x][y]) continue;
                visited[x][y] = true;

                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if (nx >= 0 && nx < n && ny >= 0 && ny < n
                        && !visited[nx][ny] && map[nx][ny]>d) {
                        q.push({ nx,ny });
                    }
                }
            }
            ans++;
        }
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> map(n, vector<int>(n));
    //높이정보

    int maxn = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            maxn = max(maxn, map[i][j]);
        }
    }

    int ans = 0;
    for (int i = 0; i <= maxn; i++) {
        ans = max(ans, solve(i, map));
    }

    cout << ans;

}