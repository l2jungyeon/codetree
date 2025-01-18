#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	//그룹의 합 간의 차이가 최소가 되도록 하는
	//중복 없음, 그룹 내에는 한개 이상

	int n;
	cin >> n;

	vector<int> vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}

	sort(vec.begin(), vec.end());

	vector<int> dp(n);//idx까지 고려했을 때 그룹 a의 최적합
	for (int i = 0; i < n; i++) {
		dp[i] = vec[i];
	}
	
	int sum = dp[0];
	for (int i = 1; i < n; i++) {		//각 원소마다
		sum += dp[i];
		for (int j = 0; j < i;j++) {	//dp 순회
			if (abs(sum - 2 * (dp[j] + vec[i])) < abs(sum - 2 * dp[i]))
				dp[i] = dp[j] + vec[i];
		}
	}

	for (int i = 0; i < n; i++) {
		cout << dp[i] << endl;
	}

	cout << abs(sum - 2*dp[n - 1]);
}
