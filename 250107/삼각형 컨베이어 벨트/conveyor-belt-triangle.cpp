#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, t;
	cin >> n >> t;

	vector<int> vec1(n);
	vector<int> vec2(n);
	vector<int> vec3(n);

	for (int i = 0; i < n; i++) {
		cin >> vec1[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> vec2[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> vec3[i];
	}

	while (t--) {
		int temp1 = vec1[n - 1];
		int temp2 = vec2[n - 1];
		int temp3 = vec3[n - 1];

		for (int i = n-1; i > 0; i--) {
			vec1[i] = vec1[i - 1];
			vec2[i] = vec2[i - 1];
			vec3[i] = vec3[i - 1];
		}

		vec1[0] = temp3;
		vec2[0] = temp1;
		vec3[0] = temp2;

	}

	for (int i = 0; i < n; i++) {
		cout << vec1[i] << " ";
	}
	cout << "\n";
	for (int i = 0; i < n; i++) {
		cout << vec2[i] << " ";
	}
	cout << "\n";
	for (int i = 0; i < n; i++) {
		cout << vec3[i] << " ";
	}
}
