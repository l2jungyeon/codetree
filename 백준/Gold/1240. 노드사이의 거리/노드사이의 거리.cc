#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

//BFS:큐
int solve(int a, int b, vector<vector<pair<int, int>>> tree) {
	int n = tree.size() - 1;
	queue<pair<int,int>> q; //자신과 부모가 연결된 거리, idx 
	vector<bool> visited(n + 1,false);
	q.push({ a,0 });

	int dist = 0;

	while (!q.empty()) {
		int start = q.front().first;
		int d = q.front().second;
		q.pop();

		if (start == b) {
			return d;
		}
		if (visited[start]) continue;
		visited[start] = true;
		
		for (pair<int,int> p : tree[start]) {
			int end = p.first;
			int endDist = p.second;
			q.push({ end, endDist + d});
		}
	}

	return 0;
}

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<pair<int,int>>> tree(n+1); //idx 0은 없음
	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		tree[a].push_back({ b,c });
		tree[b].push_back({ a,c });
	}

	while (m--) {
		int a, b;
		cin >> a >> b;
		//int dist = 0;
		
		cout << solve(a, b, tree) << "\n";
		//cout << dfs(a, b, 0, tree) << "\n";

	}
}