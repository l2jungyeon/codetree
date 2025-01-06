#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    //3*3 격자 내에

    vector<vector<int>> vec(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> vec[i][j];
        }
    }

    int large = 0;
    for (int i = 0; i <= n - 3; i++) {
        for (int j = 0; j <= n - 3; j++) {
            int l = 0;
            for (int dx = i; dx < i + 3; dx++) {
                for (int dy = j; dy < j + 3; dy++) {
                    l += vec[dx][dy];
                }
            }

            if (l > large) large = l;
        }
    }

    cout << large;
}