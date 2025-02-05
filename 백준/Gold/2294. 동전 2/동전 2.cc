#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
	int n; int k;
	cin >> n>>k;

	vector<int> vec(n);
	for (int i = 0; i < n; i++) cin >> vec[i];

	//가치가 같은 동전이 여러번 주어질수도... =>하나씩만 남기고 다 제끼기
	sort(vec.begin(), vec.end());
	vector<int> coins;
	coins.push_back(vec[0]);
	for (int i = 1; i < vec.size(); i++) {
		if (vec[i] != vec[i - 1]) {
			coins.push_back(vec[i]);
		}
	}

	n = coins.size();

	vector<int> dp(k + 1,INT_MAX);
	//사용한 동전의 최소 개수를 출력
	//dp[i]=i원을 만들기위해 필요한 동전의 최소개수
	dp[0] = 0;
	for (int i = 1; i < k+1; i++) {
		for (int j = 0; j < n; j++) {//코인별로
			int coin = coins[j];
			if (i - coin >= 0 && dp[i - coin]!=INT_MAX)
				dp[i] = min(dp[i], dp[i - coin] + 1);
		}
	}

	if (dp[k] == INT_MAX) cout << "-1";
	else cout << dp[k];
}