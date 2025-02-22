#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

// N개의 자연수 중에서 M개를 고른 수열
//중복이 없어야함->이미 넣은것을 map에 넣기

unordered_map<string, int> map;
vector<int>  ans;

void solve(int m, vector<int>& ans, vector<bool>& visited, const vector<int>& vec) {
    if (ans.size() == m) {
        string str = "";
        for (int a : ans) {
            str += (to_string(a)+" ");
        }
        if (map.find(str) != map.end()) return;
        else {
            map[str] = 1;
            for (int a : ans) {
                cout << a << " ";
            }
            cout << "\n";
        }
        return;
    }

    for (int i = 0; i < vec.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            ans.push_back(vec[i]);

            solve(m, ans, visited, vec);//vec[idx]를 넣기

            ans.erase(ans.end() - 1);
            visited[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());
    vector<bool> visited(n, false);
    solve(m, ans, visited, vec);
}