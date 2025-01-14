#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int bfs(int n) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
	//횟수, 현재 숫자
	q.push({ 0,n });

	while (!q.empty()) {
		int cnt = q.top().first;
		int num = q.top().second;
		q.pop();

		if (num == 1) return cnt;

		for (int i = 0; i < 4; i++) {
			if (i == 0) {
				q.push({ cnt + 1 , num+1 });
			}
			else if (i == 1) {
				q.push({ cnt + 1 , num-1 });
			}
			else if (i == 2 && num % 2 == 0) {
				q.push({ cnt + 1 , num / 2 });
			}
			else if (i == 3 && num % 3 == 0) {
				q.push({ cnt + 1 , num / 3 });
			}
		}
	}

}

int main() {
	int n;
	cin >> n;

	cout << bfs(n);
}