// 말이 최대한 몇 칸을 지날 수 있는지

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };

int mm = 0;

void dfs(int dist, int x, int y, const vector<vector<char>>& map, vector<bool>& visited) {
    if (dist > 26) return;
    bool flag = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < map.size() && ny >= 0 && ny < map[0].size()) {
            char nch = map[nx][ny];
            if (!visited[nch-'A']) { //없으면
                flag = false;
                visited[nch - 'A'] = true;

                dfs(dist + 1, nx, ny, map, visited);

                visited[nch - 'A'] = false;
            }
        }
    }
    if (flag) {
        mm = max(mm, dist);
        return;
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int r, c;
    cin >> r >> c;

    vector<vector<char>> map(r, vector<char>(c));

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> map[i][j];
        }
    }

    vector<bool> visited(26,false);
    //알파벳 방문 여부
    visited[map[0][0] - 'A'] = true;
    dfs(1, 0, 0, map, visited);

    cout << mm;

}