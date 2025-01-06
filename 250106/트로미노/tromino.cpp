#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve1(const vector<vector<int>>& vec, int i, int j) {
    if (i >= vec.size() - 1 || j >= vec[0].size() - 1) return -1;
    int k = vec[i][j] + vec[i + 1][j] + vec[i][j + 1] + vec[i + 1][j + 1];

    return max({ k - vec[i][j], k - vec[i + 1][j], k - vec[i][j + 1] , k - vec[i + 1][j + 1] });
}

int solve2(const vector<vector<int>>& vec, int i, int j) {
    if (j >= vec[0].size() - 2) return -1;

    return vec[i][j] + vec[i][j + 1] + vec[i][j + 2];
}

int solve3(const vector<vector<int>>& vec, int i, int j) {
    if (i >= vec.size() - 2) return -1;

    return vec[i][j] + vec[i + 1][j] + vec[i + 2][j];
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> vec(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> vec[i][j];
        }
    }

    int maxn = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int k = max({ solve1(vec, i, j), solve2(vec, i, j) ,solve3(vec,i,j)});
            if (k > maxn) maxn = k;
        }
    }

    cout << maxn;
}