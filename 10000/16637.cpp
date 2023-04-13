#include <iostream>
using namespace std;

int n, ans = -2147483648;
string s;

void input() {
	cin >> n >> s;
}

int cal(int x, int y, char c) {
	switch (c) {
	case '+':
		return x += y;
	case '-':
		return x -= y;
	case '*':
		return x *= y;
	}
	return 0;
}

void dfs(int idx, int cur) {
	if (idx >= n) {
		ans = max(ans, cur);
		return;
	}
	char op;
	if (idx == 0) op = '+';
	else op = s[idx - 1];
	if (idx + 2 < n) {
		int tmp = cal(s[idx] - '0', s[idx + 2] - '0', s[idx + 1]);
		dfs(idx + 4, cal(cur, tmp, op));
	}
	dfs(idx + 2, cal(cur, s[idx] - '0', op));
}

void solution() {
	input();
	dfs(0, 0);
	cout << ans;
}

int main() {
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(0);
	solution();
	return 0;
}
