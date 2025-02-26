#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<ll> dp(n + 1,0);
    dp[2] = 3;

    for (int i = 4; i < n + 1; i++) {
        if (i % 2 == 1) continue;
        dp[i] = dp[i - 2] * dp[2]; //뒤에서부터 2개가 한묶음. 이전의 경우는 그전과 같음

        for (int j = 4; i- j >=2 ; j++) {
            dp[i] += (dp[i - j] * 2); //여기서 *2는 i-j블럭을 제외한 나머지블럭이 한세트일 때의 경우의 수를 말함.
            //예를들어서 i가 8이고 j가 4이면, 나머지 4개가 한묶음으로 나타나는 경우가 2개임(위아래)
        }
        dp[i] += 2; //i가 한묶음인 경우
    }

    cout << dp[n];
}