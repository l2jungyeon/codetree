#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string str;
    cin >> str;

    int n;
    cin >> n;
    vector<string> dict(n);
    for (int i = 0; i < n; i++) {
        cin >> dict[i];
    }

    bool flag = true;
    while (flag) {
        for (int i = 0; i < str.size(); i++) {
            //97~122
            str[i]++;
            int a = str[i];
            if (a == 123) str[i] = 'a';
        }
        for (int i = 0; i < n; i++) {
            if (str.find(dict[i]) != string::npos) {
                flag = false;
                break;
            }
        }
    }

    cout << str;
}