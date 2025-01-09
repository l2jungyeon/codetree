#include <iostream>
#include <vector>
using namespace std;

void bomb1(vector<vector<int>>& vec, int r, int c) {
    int n = vec.size();
    if (r + 1 < n) vec[r + 1][c] = 1;
    if (r + 2 < n) vec[r + 2][c] = 1;
    if (r - 1 >= 0) vec[r - 1][c] = 1;
    if (r - 2 >= 0) vec[r - 2][c] = 1;
}

void bomb2(vector<vector<int>>& vec, int r, int c) {
    int n = vec.size();
    if (r + 1 < n) vec[r + 1][c] = 1;
    if (c + 1 < n) vec[r][c + 1] = 1;
    if (r - 1 >= 0) vec[r - 1][c] = 1;
    if (c - 1 >= 0) vec[r][c - 1] = 1;
}

void bomb3(vector<vector<int>>& vec, int r, int c) {
    int n = vec.size();
    if (r + 1 < n && c + 1 < n) vec[r + 1][c + 1] = 1;
    if (r + 1 < n && c - 1 >= 0) vec[r + 1][c - 1] = 1;
    if (r - 1 >= 0 && c + 1 < n) vec[r - 1][c + 1] = 1;
    if (r - 1 >= 0 && c - 1 >= 0) vec[r - 1][c - 1] = 1;
}

int count(vector<vector<int>> vec) {
    int total = 0;
    int n = vec.size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vec[i][j] == 1) total++;
        }
    }
    return total;
}

int total = 0;

void solve(vector<vector<int>>& vec, vector<pair<int, int>> bVec, int idx) {
    int bsize = bVec.size();
    if (idx == bsize) {
        int c = count(vec);
        if (c > total)total = c;
        return;
    }

    vector<vector<int>> nowvec = vec;
    int n = vec.size();
    int curr = bVec[idx].first;
    int curc = bVec[idx].second;

    bomb1(nowvec, curr, curc);
    solve(nowvec, bVec, idx + 1);

    vector<vector<int>> nowvec2 = vec;
    bomb2(nowvec2, curr, curc);
    solve(nowvec2, bVec, idx + 1);

    vector<vector<int>> nowvec3 = vec;
    bomb3(nowvec3, curr, curc);
    solve(nowvec3, bVec, idx + 1);

}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> vec(n,vector<int>(n));
    vector<pair<int, int>> bVec;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> vec[i][j];
            if (vec[i][j] == 1) bVec.push_back({ i,j });
        }
    }

    solve(vec, bVec, 0);
    cout << total;
}