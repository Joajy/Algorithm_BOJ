#include<iostream>
#include<stack>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, cur = 0;
	string ans;
	stack<int> s;
	cin >> n;
	while (n--) {
		int num;
		cin >> num;
		if (cur < num) {
			while (cur < num) {
				s.push(++cur);
				ans += '+';
			}
			s.pop();
			ans += '-';
		}
		else {
			if (!s.empty()) {
				if (s.top() > num) {
					cout << "NO\n";
					return 0;
				}
				s.pop();
				ans += '-';
			}
		}
	}
	for (auto i : ans)
		cout << i << '\n';
	return 0;
}
