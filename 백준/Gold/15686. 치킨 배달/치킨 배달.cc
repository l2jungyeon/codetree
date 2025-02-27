#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, m;
int ans = 1000000000;
vector<pair<int, int>> ansch;

int caldist(vector<pair<int, int>> ansch, vector<vector<int>> map) {
    int totalDist = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 1) {
                int dist = 10000000;

                for (pair<int, int> p : ansch) {
                    int cx = p.first;
                    int cy = p.second;
                    dist = min(dist, abs(i - cx) + abs(j - cy));
                }

                totalDist += dist;
            }
        }
    }

    return totalDist;
}

void solve(int idx, vector<pair<int, int>>& ansch, const vector<pair<int, int>>& chicken, const vector<vector<int>>& map) {
    if (ansch.size() == m) {
        ans = min(caldist(ansch, map), ans);
        return;
    }

    for (int i = idx; i < chicken.size(); i++) {
        ansch.push_back(chicken[i]);
        solve(i + 1, ansch, chicken, map);
        ansch.erase(ansch.end() - 1);
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> n >> m;

    vector<vector<int>> map(n, vector<int>(n));
    vector<pair<int, int>> chicken; //치킨집 좌표
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2) chicken.push_back({ i,j });
        }
    }

    solve(0, ansch, chicken, map);
    cout << ans;

}