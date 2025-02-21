#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

typedef long long ll;

int main() {
    int n;
    vector<string> vec;
    string str;
    int idx = -1;
    bool flag = true;

    while (flag) {
        cin >> str;
        stringstream sstream(str);
        string word;

        while (getline(sstream, word, ' ')) {
            if (idx == -1) {
                n = stoi(word);
            }
            else vec.push_back(word);
            idx++;
        }
        if (idx == n) {
            flag = false;
        }
    }
    
    vector<ll> ansvec(n);
    //원소를 뒤집어라...
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < vec[i].size() / 2; j++) {
            swap(vec[i][j], vec[i][vec[i].size() - j - 1]);
        }
        ansvec[i] = stoll (vec[i]);
    }

    sort(ansvec.begin(), ansvec.end());

    for (int i = 0; i < n; i++) cout << ansvec[i] << "\n";
}