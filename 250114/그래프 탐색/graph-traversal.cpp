#include <iostream>
#include <vector>
using namespace std;

void dfs(int x, int& cnt, vector<bool>& visited, vector<vector<int>> graph) {//1번정점에서 시작해서 도달할수있는 정점수
    int n = graph.size() - 1;

    for (int child : graph[x]) {
        if (!visited[child]) {
            visited[child] = true;
            dfs(child, ++cnt, visited, graph);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);//무방향
    }

    vector<bool>visited(n + 1, false);
    int cnt = 0;
    visited[1] = true;
    dfs(1, cnt, visited, graph);

    cout << cnt;

    return 0;
}