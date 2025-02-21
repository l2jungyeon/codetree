#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;


map<int, int> mapvec; //숫자, 처음 등장한 시점

bool compare(pair<int,int> a, pair<int, int> b) {
    if (a.second == b.second) {
        int c = mapvec[a.first];
        int d = mapvec[b.first];
        return c < d;
    }
    return a.second > b.second;
}

// X가 Y보다 수열에서 많이 등장하는 경우에는 X가 Y보다 앞에 있어야 한다. 만약, 등장하는 횟수가 같다면, 먼저 나온 것이 앞에 있어야 한다.
int main() {
    int n, c;
    cin >> n >> c;
    vector<pair<int, int>> vec; //숫자,등장횟수
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (mapvec.find(a) == mapvec.end()) {
            mapvec[a] = i;
        }
        bool flag = true;
        for (int j = 0; j < vec.size(); j++) {
            if (vec[j].first == a) {
                flag = false;
                vec[j].second++;
                break;
            }
        }
        if (flag) vec.push_back({ a,1 });
    }

    sort(vec.begin(), vec.end(), compare);

    for (auto& a : vec) {
        int h = a.second;
        while(h--)cout << a.first << " ";
    }
}