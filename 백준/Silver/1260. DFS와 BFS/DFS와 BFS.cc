#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

void dfs(int idx, vector<bool>& visited, vector<vector<int>> map) {
    
    cout << idx << " ";

    for (int i = 0; i < map[idx].size(); i++) {
        if (!visited[map[idx][i]]) {
            visited[map[idx][i]] = true;
            dfs(map[idx][i], visited, map);
        }
    }

    return;
}

void bfs(int v, vector<vector<int>> map) {
    vector<bool> visited(map.size(), false);
    queue<int> q;
    q.push(v);

    while (!q.empty()) {
        int curNode = q.front();
        q.pop();

        if (visited[curNode]) continue;
        visited[curNode] = true;
        cout << curNode << " ";

        for (int i = 0; i < map[curNode].size(); i++) {
            if (!visited[map[curNode][i]]) q.push(map[curNode][i]);
        }
    }
}

int main() {
    int n, m, v;
    //정점 개수, 간선 개수, 정점 번호
    cin >> n >> m >> v;

    vector<vector<int>> map(n + 1); //idx 0은 안씀
    while (m--) {
        int a, b;
        cin >> a >> b;
        map[a].push_back(b);
        map[b].push_back(a);
    }

    vector<bool> visited(n + 1, false);
    visited[v] = true;

    for (int i = 1; i < n + 1; i++) {
        sort(map[i].begin(), map[i].end()); //번호가 낮은 것 부터
    }
    dfs(v, visited, map);

    cout << endl;
    bfs(v, map);
}