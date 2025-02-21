#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

typedef long long ll;
bool compare(string s1, string s2) {
    if (s1.size() == s2.size()) {
        return s1 < s2;
    }
    return s1.size() < s2.size();
}

int main() {
    int n;
    cin >> n;
    vector<string> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end(), compare);
    vec.erase(unique(vec.begin(), vec.end()), vec.end());

    for (string s : vec) {
        cout << s << "\n";
    }
}