#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

typedef long long ll;
using namespace std;

int main() {
    int k, n;
    cin >> k >> n;
    vector<ll> vec(k);
    for (int i = 0; i < k; i++) cin >> vec[i];
    sort(vec.rbegin(), vec.rend());


    //최대 랜선의 길이
    //이분탐색!!~~!!
    ll start = 1;
    ll end = vec[0];
    ll ans = 0;
    while (start <= end) {
        ll middle = (start + end) / 2;
        ll cnt = 0;
        for (int i = 0; i < k; i++) {
            cnt += (vec[i] / middle);
        }

        if (cnt < n) end = middle-1;
        else if (cnt >= n) {
            ans = middle;
            start = middle+1;
        }
    }

    cout << ans;
}