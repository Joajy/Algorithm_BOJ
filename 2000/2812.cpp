#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

int n, k;
string num;

void input() {
	cin >> n >> k >> num;
}

void solve() {
	input();
	string answer = "";
	stack<char> s;
	n -= k;
	for (int i = 0; i < num.length(); ++i) {
		if (s.empty()) {
			s.push(num[i]);
			continue;
		}
		while (s.top() < num[i] && k > 0) {
			s.pop();
			k--;
			if (s.empty()) break;
		}
		s.push(num[i]);
	}
	while (!s.empty()) {
		answer += s.top();
		s.pop();
	}
	reverse(answer.begin(), answer.end());
	cout << answer.substr(0, n);
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solve();
	return 0;
}
