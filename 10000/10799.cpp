#include<iostream>
#include<stack>
#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std;

int main() {
	fast;
	stack<char> s;
	string r;
	int count = 0, ans = 0;
	cin >> r;
	for (int i = r.length() - 1; i >= 0; i--)		s.push(r[i]);
	while (!s.empty()) {
		char cur = s.top(); s.pop();
		if (cur == '(' && s.top() == ')') {
			ans += count;
			s.pop();
		}
		else if (cur == '(') count++;
		else {
			count--;
			ans++;
		}
	}
	cout << ans;
	return 0;
}
