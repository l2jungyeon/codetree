#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n; int m; string str;

//호출하는 함수(이후에 나오는 idx를 검사해서 p인지 확인

//bool solve(int idx) {
//	int cnt = 2*n;
//	while (n--) {
//		if (n % 2 == 0) {
//			if(str[idx])
//		}
//	}
//}

int main() {
	cin >> n;
	cin >> m;
	cin >> str;

	//idx 하나씩 가면서 I가 나올때마다 함수를 호출하는 함수
	vector<int> dp(m, 0);
	char prevChar = 'O';
	int ans = 0;
	for (int i = 0; i < m; i++) {
		char ch = str[i];
		if (ch != prevChar && i - 1 >= 0 ) {//이전꺼랑 다를때
			if (dp[i - 1] == 2*n+1)  
				dp[i] = dp[i - 1] - 1;
			else 
				dp[i] = dp[i - 1] + 1;
			prevChar = ch;
		}
		else if (ch == 'I') {
			//이전꺼랑은 이어지지않지만
			//새로 시작할 수 있을 때
			prevChar = ch;
			dp[i] = 1;
		}
		if (dp[i] == 2 * n + 1) ans++;
	}

	cout << ans;

}