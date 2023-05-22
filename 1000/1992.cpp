#include<iostream>
using namespace std;
#define HALF tileSize / 2
#define MAX 1 << 6

int n;
char board[MAX][MAX];

void input() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < s.length(); ++j) {
			board[i][j] = s[j];
		}
	}
}

void rec(int x, int y, int tileSize) {
	char cur = board[x][y];
	for (int i = x; i < x + tileSize; ++i) {
		for (int j = y; j < y + tileSize; ++j) {
			if (board[i][j] == cur) continue;
			cout << '(';
			rec(x, y, HALF);
			rec(x, y + HALF, HALF);
			rec(x + HALF, y, HALF);
			rec(x + HALF, y + HALF, HALF);
			cout << ')';
			return;
		}
	}
	cout << cur;
}

void solution() {
	rec(0, 0, n);
}

int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
	input();
	solution();
	return 0;
}
