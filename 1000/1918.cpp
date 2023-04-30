#include<iostream>
#include<stack>
using namespace std;

void solution(string str) {
	stack<char> s;
	for (char c : str) {
		switch (c) {
		case '(':
			s.push(c);
			break;
		case ')':
			while (!s.empty() && s.top() != '(') {
				cout << s.top();
				s.pop();
			}
			s.pop();
			break;
		case '/':
		case '*':
			while (!s.empty() && (s.top() == '/' || s.top() == '*')) {
				cout << s.top();
				s.pop();
			}
			s.push(c);
			break;
		case '+':
		case '-':
			while (!s.empty() && s.top() != '(')
			{
				cout << s.top();
				s.pop();
			}
			s.push(c);
			break;
		default:
			cout << c;
		}
	}
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	string s;
	cin >> s;
	solution(s);
	return 0;
}
