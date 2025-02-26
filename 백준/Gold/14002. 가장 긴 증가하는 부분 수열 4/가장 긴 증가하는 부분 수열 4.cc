#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) cin >> vec[i];
    
    vector<vector<int>> dpnum(n); //그 수열
    dpnum[0].push_back(vec[0]);
    
    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (vec[i] > vec[j] && dpnum[i].size()<dpnum[j].size()) {
                dpnum[i] = dpnum[j];
            }
        }
        dpnum[i].push_back(vec[i]);
    }

    int ans = 0;
    vector<int> ansvec;
    for (int i = 0; i < n; i++) {
        int cnt = dpnum[i].size();
        if (cnt > ans) {
            ansvec = dpnum[i];
            ans = cnt;
        }
    }

    cout << ans<< "\n";
    for (int i : ansvec) {
        cout << i << " ";
    }

}