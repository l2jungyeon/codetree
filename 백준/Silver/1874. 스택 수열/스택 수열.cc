#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> vec(n);	//1부터 n까지 저장되어있음
	vector<int> ansVec(n);		//만들어야할 수열
	vector<char> ans;
	for (int i = 0; i < n; i++) {
		vec[i] = i + 1;
		cin >> ansVec[i];
	}

	stack<int> stack;
	int ansidx = 0; //ansVec의 idx
	int idx = 1;//vec의 idx
	stack.push(vec[0]);
	ans.push_back('+');

	while (idx!=n || !stack.empty()) {
		if (!stack.empty() && stack.top() == ansVec[ansidx]) {
			//pop
			ans.push_back('-');
			stack.pop();
			ansidx++;
		}
		else if(idx<n){
			//push
			ans.push_back('+');
			stack.push(vec[idx]);
			idx++;
		}
		else {
			break;
		}
	}

	if (ansidx != n) cout << "NO";
	else {
		for (char ch : ans) {
			cout << ch << "\n";
		}
	}
}