#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    //연속해서 m개 이상 동일한 원소가 나옴

    vector<vector<int>> vec(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> vec[i][j];
        }
    }

    int total = 0;
    for (int i = 0; i < n; i++) {   //각 행에 대해
        int combo = 1;//연속한 개수
        int num = vec[i][0]; //연속한 숫자
        for (int j = 1; j < n; j++) {
            if (vec[i][j] == num) combo++;
            else
            {
                combo = 1;
                num = vec[i][j];
            }
        }
        if (combo >= m) total++;
    }

    for (int i = 0; i < n; i++) {   //각 열에 대해
        int combo = 1;//연속한 개수
        int num = vec[0][i]; //연속한 숫자
        for (int j = 1; j < n; j++) {
            if (vec[j][i] == num) combo++;
            else
            {
                combo = 1;
                num = vec[j][i];
            }
        }
        if (combo >= m) total++;
    }

    cout << total;
}