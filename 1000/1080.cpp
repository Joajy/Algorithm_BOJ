#include<iostream>
using namespace std;

int n, m, answer = 0;
int a[51][51];
int b[51][51];

void input() {
	cin >> n >> m;
	string s;
	for (int i = 1; i <= n; ++i) {
		cin >> s;
		for (int j = 1; j <= s.length(); ++j) {
			a[i][j] = s[j - 1] - '0';
		}
	}
	for (int i = 1; i <= n; ++i) {
		cin >> s;
		for (int j = 1; j <= s.length(); ++j) {
			b[i][j] = s[j - 1] - '0';
		}
	}
}

void flip(int x, int y, int(*a)[51]) {
	for (int i = x; i < x + 3; ++i) {
		for (int j = y; j < y + 3; ++j) {
			a[i][j] = !a[i][j];
		}
	}
}

void solution() {
	input();
	for (int i = 1; i < n - 1; ++i) {
		for (int j = 1; j < m - 1; ++j) {
			if (a[i][j] == b[i][j]) continue;
			flip(i, j, a);
			++answer;
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (a[i][j] == b[i][j]) continue;
			cout << -1;
			return;
		}
	}
	cout << answer;
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
