#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(const vector<vector<int>>& vec, int r, int c, int k, int m) {
    //k= 마름모크기, m=금 한개당 가격
    int totalGold = vec[r][c];
    int size = vec.size();
   
    for (int i = 1; i < k; i++) {
        for (int j = 1; j < k; j++) {
            if (r - i >= 0 && c - j >= 0)  totalGold += vec[r - i][c - j];
            if (r + i < size && c + j < size)  totalGold += vec[r + i][c + j];
            if (r - i >= 0 && c + j < size) totalGold += vec[r - i][c + j];
            if (r + i < size && c - j >= 0)  totalGold += vec[r + i][c - j];
        }
    }

    for (int i = 1; i <= k; i++) {
        if (r - i >= 0) totalGold += vec[r - i][c];
        if (r + i < size) totalGold += vec[r + i][c];
        if (c - i >= 0) totalGold += vec[r][c-i];
        if (c + i < size) totalGold += vec[r][c+i];
    }

    if (totalGold * m < k * k + (k + 1) * (k + 1)) return -1;
    else return totalGold;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> vec(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> vec[i][j];
        }
    }

    int maxgold = 0;//최대 금의 개수
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k <= n; k++) {//마름모 크기에 따라서..
                int goldk = solve(vec,i,j,k,m);
                if (maxgold < goldk) maxgold = goldk;
            }
        }
    }

    cout << maxgold;
}