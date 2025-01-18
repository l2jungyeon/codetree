#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

int main() {
	//그룹의 합 간의 차이가 최소가 되도록 하는
	//중복 없음, 그룹 내에는 한개 이상

	int n;
	cin >> n;

	vector<int> vec(n);
	int m = 0;
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
		m += vec[i];
	}

	sort(vec.begin(), vec.end());

	vector<bool> dp(m+1, false); //idx라는 수를 주어진 원소로 만들 수 있는가?
	dp[0] = true;
	
	for (int i = 0; i < n; i++) {		//각 원소마다
		for (int j = m; j >=0;j--) {	//dp 순회
			if (j>=vec[i] && dp[j-vec[i]])
				dp[j] = true;
		}
	}

	int ans = INT_MAX;
	for (int i = 0; i < m+1; i++) {
		if (dp[i])
			ans = min(ans,abs(m - 2 * i));
	}

	cout << ans;
}
