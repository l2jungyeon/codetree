#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

const int dx[] = { 0,0,1,-1 };
const int dy[] = { 1,-1,0,0 };

void dfs(int row, int col, const vector<vector<int>>& graph, 
    vector<vector<bool>>& visited, pair<int,int>& p1) {
    int n = graph.size();
    int curnum = graph[row][col];
    
    for (int i = 0; i < 4; i++) {
        int nextrow = row + dx[i];
        int nextcol = col + dy[i];

        //범위에서 벗어나지 않고, 방문한적이 없으며, 숫자가 같은 경우 block 업데이트
        if (nextrow < n && nextrow >= 0 && nextcol < n && nextcol >= 0 
            && !visited[nextrow][nextcol] && graph[nextrow][nextcol] == curnum) {
            p1.second += 1;
            visited[nextrow][nextcol] = true;
            dfs(nextrow, nextcol, graph, visited, p1);
        }
    }
}

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    vector<pair<int, int>> pVec;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //graph[i][j]에 해당하는 숫자와 터지는걸 잘 보기
            if (!visited[i][j]) {
                visited[i][j] = true;
                pair<int, int> p1 = { graph[i][j], 1};
                dfs(i, j, graph, visited, p1);
                pVec.push_back(p1);
            }
        }
    }

    int cnt = 0;
    int large = 0;
    for (pair<int, int>p : pVec) {
        if (p.second >= 4) cnt++;
        if (p.second > large)large = p.second;
    }

    cout << cnt << " " << large;
}