#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int plusf(int a) { return a + 1; }
int minusf(int a) { return a - 1; }
int divideTwo(int a) { return a / 2; }
int divideThree(int a) { return a / 3; }

int bfs(int n) {
	queue<pair<int,int>> q;//현재 숫자, 횟수
	q.push({n,0});
	
	while (!q.empty()) {
		int num = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (num == 1) return cnt;

		for (int i = 0; i < 4; i++) {
			if (i == 0) {
				q.push({ plusf(num),cnt + 1 });
			}
			else if (i == 1) {
				q.push({ minusf(num),cnt + 1 });
			}
			else if (i == 2 && num % 2 == 0) {
				q.push({ divideTwo(num),cnt + 1 });
			}
			else if (i == 3 && num % 3 == 0) {
				q.push({ divideThree(num),cnt + 1 });
			}
		}
	}

}

int main() {
	int n;
	cin >> n;

	cout << bfs(n);
}