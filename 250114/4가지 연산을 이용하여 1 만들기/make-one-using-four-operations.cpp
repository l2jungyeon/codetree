#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct compare {
	bool operator()(pair<int, int> p1, pair<int, int> p2) {
		// 1. 횟수가 작은 것이 우선
		if (p1.second != p2.second) {
			return p1.second > p2.second; // 횟수가 작은 것 우선
		}

		// 2. 숫자가 3으로 나누어떨어지는 것이 우선
		if ((p1.first % 3 == 0) != (p2.first % 3 == 0)) {
			return (p1.first % 3 != 0);
		}

		// 3. 숫자가 2로 나누어떨어지는 것이 우선
		if ((p1.first % 2 == 0) != (p2.first % 2 == 0)) {
			return (p1.first % 2 != 0);
		}

		// 기본적으로 숫자가 작은 것이 우선
		return p1.first > p2.first;
	}
};


int bfs(int n) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> q;
	//queue<pair<int, int>> q;
	//현재 숫자, 횟수
	q.push({ n,0 });

	vector<int> cntVec;

	while (!q.empty()) {
		int cnt = q.top().second;
		int num = q.top().first;
		q.pop();

		if (num == 1) { return cnt; }

		if (num % 3 == 0) q.push({ num / 3,cnt + 1 });
		else {
			int k = num % 3;
			q.push({ (k + num) / 3,cnt + 1 + k });
			if (num-k >= 3)	q.push({ (num-k) / 3, cnt + 1 + k });
		}

		if (num % 2 == 0) q.push({ num / 2,cnt + 1 });
		else {
			int l = num % 2;
			q.push({ (l + num) / 2, cnt + 1 + l });
			if (num-l >= 2)	q.push({ (num-l) / 2, cnt + 1 + l });
		}
	}
}

int main() {
	int n;
	cin >> n;

	cout << bfs(n);
}