#include <iostream>
#include <vector>
using namespace std;

void dfs(int x, int& cnt, vector<bool>& visited, const vector<vector<int>>& graph) {//1번정점에서 시작해서 도달할수있는 정점수
    int n = graph.size() - 1;

    for (int i = 1; i < n + 1; i++) {
        if (!visited[i] && graph[x][i]) {
            visited[i] = true;
            dfs(i, ++cnt, visited, graph);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1, vector<int>(n+1, false));
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x][y] = true;
        graph[y][x] = true;
    }

    vector<bool>visited(n + 1, false);
    int cnt = 0;
    visited[1] = true;
    dfs(1, cnt, visited, graph);

    cout << cnt;

    return 0;
}