#include<iostream>
using namespace std;

int N, r, c, answer = 0;

void input() {
	cin >> N >> r >> c;
}

void dfs(int x, int y, int n) {
	if (x == r && y == c) {
		cout << answer;
		return;
	}
	if (r >= x && r < x + n && c >= y && c < y + n) {
		n >>= 1;
		dfs(x, y, n);
		dfs(x, y + n, n);
		dfs(x + n, y, n);
		dfs(x + n, y + n, n);
	}
	else {
		answer += n * n;
	}
}

void solution() {
	input();
	dfs(0, 0, 1 << N);
}

int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
