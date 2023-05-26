#include<iostream>
using namespace std;
#define MAX 128
int a[MAX][MAX];
int n, white = 0, blue = 0;

void input() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j];
		}
	}
}

bool div(int x, int y, int size) {
	int color = a[x][y];	//0:white, 1:blue
	for (int i = x; i < x + size; ++i) {
		for (int j = y; j < y + size; ++j) {
			if (a[i][j] != color) return true;
		}
	}
	if (color == 0) ++white;
	else ++blue;
	return false;
}

void dfs(int x, int y, int size) {
	if (size == 0) return;
	if (!div(x, y, size)) return;
	dfs(x, y, size >> 1);
	dfs(x, y + size / 2, size >> 1);
	dfs(x + size / 2, y, size >> 1);
	dfs(x + size / 2, y + size / 2, size >> 1);
}

void solution() {
	input();
	dfs(0, 0, n);
	cout << white << '\n' << blue;
}

int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
