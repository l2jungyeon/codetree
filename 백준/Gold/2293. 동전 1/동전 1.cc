#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
	int n, k;
	cin >> n >> k;
	//n가지 동전을 사용해서 k원 만들기.
	//여러개 사용해도 ㄱㅊ

	vector<int> coins(n);
	for (int i = 0; i < n; i++)cin >> coins[i];

	vector<ll> dp(k + 1);
	//dp[i] = i원을 만들 수 있는 동전의 가짓수
	//사용한 동전의 구성이 같은데, 순서만 다른 것은 같은 경우이다.

	dp[0] = 1;
	for (int j = 0; j < n; j++) {//coin별로
		int coin = coins[j];
		for (int i = 1; i < k + 1; i++) {//i원 만들기
			if (i - coin >= 0)
				dp[i] += dp[i - coin];
		}
	}

	cout << dp[k];
}