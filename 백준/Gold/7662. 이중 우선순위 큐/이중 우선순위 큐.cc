#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int k;
        cin >> k;

        priority_queue<ll, vector<ll>, greater<>> min_queue;
        priority_queue<ll, vector<ll>, less<>> max_queue;
        unordered_map<ll, int> visited; // 방문 카운팅 방식으로 처리

        for (int i = 0; i < k; i++) {
            char c;
            ll n;
            cin >> c >> n;

            if (c == 'I') {
                min_queue.push(n);
                max_queue.push(n);
                visited[n]++;
            } else { // 삭제 연산
                if (n == -1) { // 최솟값 삭제
                    while (!min_queue.empty()) {
                        ll top = min_queue.top();
                        min_queue.pop();
                        if (visited[top] > 0) {
                            visited[top]--;
                            break;
                        }
                    }
                } else if (n == 1) { // 최댓값 삭제
                    while (!max_queue.empty()) {
                        ll top = max_queue.top();
                        max_queue.pop();
                        if (visited[top] > 0) {
                            visited[top]--;
                            break;
                        }
                    }
                }
            }
        }

        while (!max_queue.empty()) {
            ll top = max_queue.top();
            if (visited[top] > 0) break;
            max_queue.pop();
        }

        while (!min_queue.empty()) {
            ll top = min_queue.top();
            if (visited[top] > 0) break;
            min_queue.pop();
        }

        if (max_queue.empty() || min_queue.empty()) {
            cout << "EMPTY\n";
        } else {
            cout << max_queue.top() << " " << min_queue.top() << "\n";
        }
    }
}
