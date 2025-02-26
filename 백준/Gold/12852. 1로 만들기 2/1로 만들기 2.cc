#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vec(n+1, INT_MAX);
    vector<vector<int>> vecnum(n+1);

    vec[1] = 0;
    vecnum[1].push_back(1);
    //n을 1로 만드는 방법

    for (int i = 2; i <= n; i++) {
        if (i % 3 == 0) {
            vec[i] = min(vec[i / 3] + 1, vec[i]);
            vecnum[i] = vecnum[i / 3];
        }
        if (i % 2 == 0) {
            vec[i] = min(vec[i / 2] + 1, vec[i]);
            if (vec[i] == vec[i / 2] + 1) {
                vecnum[i] = vecnum[i / 2];
            }
        }
        vec[i] = min(vec[i], vec[i - 1] + 1);
        if (vec[i] == vec[i - 1] + 1) {
            vecnum[i] = vecnum[i - 1];
        }
        vecnum[i].push_back(i);
    }

    cout << vec[n] << "\n";
    for (int it = vecnum[n].size() - 1; it >= 0;it--) {
        cout << vecnum[n][it] << " ";
    }
}