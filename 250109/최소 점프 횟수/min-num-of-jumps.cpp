#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> jmps;

void solve(int curIdx, int jmp, const vector<int>& vec) {
	int n = vec.size();

	if (curIdx >= n)//넘어간경우
	{
		return;
	}
	if (curIdx == n - 1) {
		//도달한 경우
		jmps.push_back(jmp);
		return;
	}

	int curjmp = jmp;
	int curmaxjmp = vec[curIdx];
	for (int i = 1; i <= curmaxjmp; i++) {
		solve(curIdx + i, curjmp + 1, vec);
	}
	
	return;
}

int main() {
	int n;
	cin >> n;

	vector<int> vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}

	solve(0, 0, vec);

	if (jmps.empty()) cout << "-1";
	else {
		sort(jmps.begin(), jmps.end());
		cout << jmps[0];
	}
}