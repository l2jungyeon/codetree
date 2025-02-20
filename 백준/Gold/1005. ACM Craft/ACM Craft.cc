#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

typedef long long ll;
using namespace std;

ll solve(int w, vector<int> indeg, vector<int> time, vector < vector<int> >map) {
    int n = indeg.size() - 1;

    queue<pair<int, int>> q;     //<단계, idx>
    vector<ll> dp(n + 1);

    for (int i = 1; i < n + 1; i++) {
        if (indeg[i] == 0) {
            q.push({ 0,i });
            dp[i] = time[i];
        }
    }

    while (!q.empty()) {
        int cur = q.front().second;
        int stage = q.front().first;
        q.pop();

        if (cur == w) {
            return dp[w];
        }

        for (int i = 0; i < map[cur].size(); i++) {
            int next = map[cur][i];
            indeg[next]--;
            dp[next] = max(dp[cur] + time[next], dp[next]);
            if (indeg[next] == 0) 
                q.push({ stage + 1,next });
        }
    }

    return dp[w];
    }

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> time(n + 1);//idx 0은 안씀
        for (int i = 0; i < n; i++) cin >> time[i + 1];

        vector<int> indeg(n + 1); //idx의 부모들이 몇개?
        vector < vector<int>> map(n + 1);
        vector < vector<int> >parmap(n + 1); //부모의 개수
        while (k--) {
            int a, b;
            cin >> a >> b;

            map[a].push_back(b);
            parmap[b].push_back(a);
        }
        for (int i = 1; i < n + 1; i++) {
            indeg[i] = parmap[i].size();
        }

        int w;
        cin >> w;

        cout << solve(w, indeg, time, map) << "\n";

    }
}