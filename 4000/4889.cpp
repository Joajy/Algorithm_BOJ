#include<iostream>
#include<stack>
using namespace std;

void solution() {
	string str;
	for (int t = 1;; ++t) {
		cin >> str;
		if (str[0] == '-') return;
		stack<char> s;
		int answer = 0;
		for (int i = 0; i < str.length(); ++i) {
			if (s.empty()) {
				s.push(str[i]);
				continue;
			}
			if (s.top() == '{' && str[i] == '}') {
				s.pop();
			}
			else {
				s.push(str[i]);
			}
		}
		while (!s.empty()) {
			if (s.top() == '{') {
				++answer;
				s.pop();
				if (s.top() == '}') ++answer;
				s.pop();
			}
			else {
				s.pop();
				if (s.top() == '}') ++answer;
				s.pop();
			}
		}
		cout << t << ". " << answer << '\n';
	}
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
