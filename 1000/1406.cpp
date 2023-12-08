#include <iostream>
#include <string>
#include <stack>
using namespace std;

int n;
stack<char> l, r;

void init() {
	string s;
	cin >> s >> n;
	for (char i : s) {
		l.push(i);
	}
}

void solution() {
	init();
	char cmd;
	for (int i = 0; i < n; ++i) {
		cin >> cmd;
		if (cmd == 'P') {
			cin >> cmd;
			l.push(cmd);
		}
		else if(cmd == 'L') {
			if (l.empty()) continue;
			r.push(l.top());
			l.pop();
		}
		else if (cmd == 'D') {
			if (r.empty()) continue;
			l.push(r.top());
			r.pop();
		}
		else if (cmd == 'B') {
			if (l.empty()) continue;
			l.pop();
		}
	}
	while (!l.empty()) {
		r.push(l.top());
		l.pop();
	}
	while (!r.empty()) {
		cout << r.top();
		r.pop();
	}
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
