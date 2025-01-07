#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//아래오, 아래왼, 위오, 위왼
//2 1 1 2
const int dx[] = { -1,-1,1,1 };
const int dy[] = {1,-1,-1,1 };

//갈수있는게 여러개면 다 가보고 최대로?
int solve(vector<vector<int>> vec, int r, int c, int k, int l) {
    int size = vec.size();
    int movenum[] = { k,l,k,l };

    int total = 0;
    for (int d = 0; d < 4; d++) {
        for (int q = 0; q < movenum[d]; q++) {
            r += dx[d]; c += dy[d];
            if (r < 0 || r >= size || c >= size || c < 0)
                return 0;
            else 
                total += vec[r][c];
        }
    }

    return total;
}


int main() {
    int n;
    cin >> n;

    vector<vector<int>> vec(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> vec[i][j];
        }
    }

    int total = 0;
    for (int i = 0; i < n; i++) {           //현재 x좌표
        for (int j = 0; j < n; j++) {       //현재 y좌표
            for (int k = 1; k < n; k++) {   //1,3번 이동시 거리
                for (int l = 1; l < n; l++) {//2,4번 이동시 거리
                    int s = solve(vec, i, j, k, l);
                    if (s > total) total = s;
                }
            }
        }
    }

    cout << total;

}
