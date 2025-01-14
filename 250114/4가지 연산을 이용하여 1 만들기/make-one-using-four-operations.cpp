#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int bfs(int n) {
	queue<pair<int, int>> q;
	//현재 숫자, 횟수
	q.push({ n,0 });
	vector<bool> visited(2000001, false);

	while (!q.empty()) {
		int num = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (num == 1) return cnt;
		if (visited[num]) continue;
		visited[num] = true;

		for (int i = 0; i < 4; i++) {
			if (i == 0)q.push({ num + 1,cnt + 1 });
			else if (i == 1)q.push({ num - 1,cnt + 1 });
			else if (i == 2 && num % 3==0)q.push({ num / 3,cnt + 1 });
			else if (i == 3 && num % 2==0)q.push({ num / 2,cnt + 1 });
		}
	}
}

int main() {
	int n;
	cin >> n;

	cout << bfs(n);
}