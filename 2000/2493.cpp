#include<iostream>
#include<stack>
using namespace std;
#define p pair<int, int>

int n;
stack<p> s;

void solution() {
	cin >> n;
	s.push(make_pair(1 << 29, 0));
	for (int i = 1; i <= n; ++i) {
		int h;
		cin >> h;
		while (s.top().first < h) {
			s.pop();
		}
		cout << s.top().second << ' ';
		s.push(make_pair(h, i));
	}
}

int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
