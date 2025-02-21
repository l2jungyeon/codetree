#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//bfs
int bfs(int start, int end, vector<vector<pair<int, int>>> tree) {
    queue<pair<int, int>> q; //거리, 노드
    q.push({ 0,start });

    vector<bool> visited(tree.size(), false);
    while (!q.empty()) {
        int dist = q.front().first;
        int node = q.front().second;
        q.pop();

        if (visited[node]) continue;
        visited[node] = true;

        if (node == end) {
            return dist;
        }

        for (auto& p : tree[node]) {
            if (!visited[p.first])
                q.push({ dist + p.second, p.first });
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> tree(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        tree[a].push_back({ b,c });
        tree[b].push_back({ a,c });
    }

    while (m--) {
        int a, b;
        cin >> a >> b;
        cout << bfs(a, b, tree) << "\n";
    }

}