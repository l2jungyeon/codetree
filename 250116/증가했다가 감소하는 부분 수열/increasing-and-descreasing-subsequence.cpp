#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}

	vector<int> updp(n,1);
	vector<int> downdp(n,1);
	vector<int> updowndp(n, 1);

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (vec[i] > vec[j]) {
				updp[i] = max(updp[j] + 1, updp[i]);
			}
			else if (vec[i] < vec[j]) {
				downdp[i] = max(downdp[j] + 1, downdp[i]);

				if (updowndp[j] > 1) { //증가했다가 감소하는 수열이었을 때
					updowndp[i] = max(updowndp[j] + 1, updowndp[i]);
				}
				else if (updp[j] > 1) {//증가했다가 감소하는 수열의 첫 감소 부분일 때
					updowndp[i] = max(updp[j] + 1, updowndp[i]);
				}
			}
		}
	}

	int large=0;
	for (int i = 0; i < n; i++) {
		large = max({ large, updp[i],downdp[i],updowndp[i] });
	}

	cout << large;
}
