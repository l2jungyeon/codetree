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
        vector<pair<int, int>> comboNum;
        int idx = 0;
        comboNum.push_back({ 1,vec[i][0] });
        for (int j = 1; j < n; j++) {
            if (vec[i][j] == comboNum[idx].second) comboNum[idx].first+=1;
            else
            {
                idx++;
                comboNum.push_back({ 1,vec[i][j] });
            }
        }
        for (int k = 0; k < comboNum.size(); k++) {
            if (comboNum[k].first >= m) {
                total += 1;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        vector<pair<int, int>> comboNum;
        int idx = 0;
        comboNum.push_back({ 1,vec[0][i] });
        for (int j = 1; j < n; j++) {
            if (vec[j][i] == comboNum[idx].second) comboNum[idx].first += 1;
            else
            {
                idx++;
                comboNum.push_back({ 1,vec[j][i] });
            }
        }
        for (int k = 0; k < comboNum.size(); k++) {
            if (comboNum[k].first >= m) {
                total += 1;
                break;
            }
        }
    }

    cout << total;
}