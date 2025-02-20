#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int dh[6] = { 0,0,0,0,1,-1 };
int dx[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };

// 하나의 토마토에 인접한 곳은 위, 아래, 왼쪽, 오른쪽, 앞, 뒤 여섯 방향에
//bfs
int m, n, h;

bool check(vector<vector<vector<bool>>> visited) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (!visited[i][j][k]) return false;
            }
        }
    }

    return true;
}
int bfs(vector<vector<vector<int>>> map) {
    vector<vector<vector<bool>>> visited(h, vector<vector<bool>>(n, vector<bool>(m, false)));

    queue<tuple<int, int, int>> q;
    queue<int> dateq;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (map[i][j][k] == 1) {
                    q.push({ i,j,k });
                    dateq.push(0);
                }
                if (map[i][j][k] == -1) visited[i][j][k] = true;
            }
        }
    }

    int maxday = -1;
    while (!q.empty()) {
        //cout << "love";
        int ch = get<0>(q.front());
        int cx = get<1>(q.front());
        int cy = get<2>(q.front());
        int day = dateq.front();

        q.pop();
        dateq.pop();

        if (visited[ch][cx][cy]) continue;
        visited[ch][cx][cy] = true;

        maxday = max(maxday, day);

        for (int i = 0; i < 6; i++) {
            int nh = ch + dh[i];
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nh >= 0 && nh < h && nx >= 0 && nx < n && ny >= 0 && ny < m){
                if (!visited[nh][nx][ny] && (map[nh][nx][ny] == 0)) {
                    q.push({ nh,nx,ny });
                    dateq.push(day + 1);
                }
            }
        }
    }

    if (check(visited)) {
        return maxday;
    }
    else {
        return -1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> m >> n >> h;

    vector<vector<vector<int>>> map(h, vector<vector<int>>(n, vector<int>(m)));

    int flag = 0; //모든 토마토가 익은 상태
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cin >> map[i][j][k];
                //정수 1은 익은 토마토, 정수 0 은 익지 않은 토마토, 
                // 정수 -1은 토마토가 들어있지 않은 칸
                if (map[i][j][k] == 0) {
                    //안익은게 하나라도 있으면
                    flag = 1;
                }
            }
        }
    }

    if (flag == 0) {
        cout << "0";
    }
    else cout << bfs(map);

}