#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

typedef long long ll;
using namespace std;

int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    //a를 b번 곱한 후 c로 나눈 나머지
    
    vector<ll> dp; //dp[i] = a^2^i
    dp.push_back(a);
    int maxI = -1;
    for (int i = 1; i < INT_MAX; i++) {
        if (pow(2, i) > b) {
            maxI = i-1;
            break;
        }
        dp.push_back((dp[i - 1] * dp[i - 1])%c);
    }

    ll sum = 1;
   
    while (b!=0) {
        b -= pow(2, maxI);
        sum = (sum*dp[maxI])%c;
        for (int i = dp.size() - 1; i >= 0; i--) {
            if (pow(2, i) <= b) {
                maxI = i;
                break;
            }
        }
    }

    cout << sum;
}