#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<ll> card(n);
    for (int i = 0; i < n; i++) cin >> card[i];

    sort(card.begin(), card.end());

    unordered_map<ll, int> map; //숫자, 몇개
    ll prevn = 0;
    for (int i = 0; i < n; i++) {
        if (prevn == card[i]) {
            map[prevn] += 1;
        }
        else {
            prevn = card[i];
            map[prevn] = 1;
        }
    }

    ll maxcount = 0;
    ll maxn = 0;
    for (auto& a : map) {
        if (maxcount < a.second) {
            maxn = a.first;
            maxcount = a.second;
        }
        else if (maxcount == a.second) {
            maxn = min(a.first, maxn);
        }
    }

    cout << maxn;
}