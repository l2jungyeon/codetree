#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	//회의실배정이랑 유사...
	//끝나는게 일찍인 순으로 정렬
	//앞에서부터?

	vector<pair<int, int>> vec; //x2,x1순으로
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		vec.push_back({ b,a });
	}

	sort(vec.begin(), vec.end());
	int total = 0;
	int preEnd = 0;
	for (int i = 0; i < n; i++) {
		int start = vec[i].second;
		if (preEnd < start) {
			total++;
			preEnd = vec[i].first;
		}
	}

	cout << total;
}
