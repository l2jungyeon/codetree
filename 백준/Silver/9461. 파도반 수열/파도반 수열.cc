#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

#define N 100

int main() {
	int t;
	cin >> t;
	
	vector<ll> pVec = { 0,1, 1, 1, 2, 2, 3, 4, 5, 7, 9, };
	for (int i = 11; i < N + 1; i++) {
		pVec.push_back(pVec[i - 1] + pVec[i - 5]);
	}

	while (t--) {
		int n;

		cin >> n;
		cout << pVec[n]<<"\n";
	}
}