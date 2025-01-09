#include <iostream>
#include <vector>
using namespace std;

int total = 0;

void solve(int curidx, int n) {
	if (curidx > n + 1) return;
	if (curidx == n + 1) {
		total += 1;
		return;
	}

	//1이상 4이하
	for (int i = 1; i < 5; i++) {
		solve(curidx + i, n);
	}

	return;
}

int main() {
	int n;
	cin >> n;
	
	solve(1, n);
	cout << total;
}