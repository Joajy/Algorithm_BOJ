#include <iostream>
using namespace std;

string l, r;

void input() {
	cin >> l >> r;
}

void solution() {
	input();
	if (l.length() != r.length()) {
		cout << 0;
		return;
	}
	int cnt = 0;
	for (int i = 0; i < l.length(); ++i) {
		if (l[i] != r[i]) {
			cout << cnt;
			return;
		}
		if (l[i] == '8' && l[i] == r[i]) {
			++cnt;
		}
	}
	cout << cnt;
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
