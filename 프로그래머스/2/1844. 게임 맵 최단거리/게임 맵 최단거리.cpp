#include <vector>
#include <queue>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

//bfs
int solve(vector<vector<int>> maps) {
    int n = maps.size();
    int m = maps[0].size();
    
    // visited 배열을 maps를 직접 수정하는 방식으로 변경
    queue<pair<int, int>> q;
    q.push({0, 0});
    maps[0][0] = 1; // 시작점도 카운트
    
    while(!q.empty()) {
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();
        
        // 도착점에 도달한 경우
        if(curx == n-1 && cury == m-1) {
            return maps[curx][cury];
        }
        
        // 4방향 탐색
        for(int i = 0; i < 4; i++) {
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            
            // 범위 체크 및 방문하지 않은 빈 칸 체크
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && maps[nx][ny] == 1) {
                maps[nx][ny] = maps[curx][cury] + 1; // 거리 업데이트
                q.push({nx, ny});
            }
        }
    }
    
    return -1; // 도달할 수 없는 경우
}

int solution(vector<vector<int> > maps)//0은 벽이 있는 자리, 1은 벽이 없는 자리
{
    int answer = 0;
    answer = solve(maps);
    return answer;//칸의 개수의 최솟값(없으면 -1)
}