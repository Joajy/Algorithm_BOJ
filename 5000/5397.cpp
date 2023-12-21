#include <iostream>
#include <string>
#include <stack>
using namespace std;

int n;
string str;

void solution() {
	stack<char> l, r;
	cin >> str;
	for (int i = 0; i < str.length(); ++i) {
		if (str[i] == '<') {
			if (!l.empty()) {
				r.push(l.top());
				l.pop();
			}
		}
		else if(str[i] == '>') {
			if (!r.empty()) {
				l.push(r.top());
				r.pop();
			}
		}
		else if (str[i] == '-') {
			if (l.empty()) continue;
			l.pop();
		}
		else {
			l.push(str[i]);
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
	cout << '\n';
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n;
	while (n--) {
		solution();
	}
	return 0;
}
