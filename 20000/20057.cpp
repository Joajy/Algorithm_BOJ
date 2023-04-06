#include <iostream>
using namespace std;
int n, ans;
const int MAX = 501;

int a[MAX][MAX];
int dx[4]{ 0,1,0,-1 };
int dy[4]{ -1,0,1,0 };
int xdx[4][9]{
	{ -1, 1, -1, 1, -1, 1, -2, 2, 0} ,
	{ 0, 0, 1, 1, 2, 2, 1, 1, 3},
	{ -1, 1, -1, 1, -1, 1, -2, 2, 0,},
	{ 0, 0, -1, -1, -2, -2, -1, -1, -3},
};
int ydy[4][9]{
	{ 0, 0, -1, -1, -2, -2, -1, -1, -3},
	{ -1, 1, -1, 1, -1, 1, -2, 2, 0},
	{ 0, 0, 1, 1, 2, 2, 1, 1, 3},
	{-1, 1, -1, 1, -1, 1, -2, 2, 0},
};
int percent[9]{ 1, 1, 7, 7, 10, 10, 2, 2, 5 };

void input() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
}

void sparse(int x, int y, int dir) {
	int nx = x + dx[dir];
	int ny = y + dy[dir];
	if (a[nx][ny] == 0) return;

	int mx, my;
	int sand = a[nx][ny];

	for (int i = 0; i < 9; i++) {
		mx = x + xdx[dir][i];
		my = y + ydy[dir][i];
		int sum = (a[nx][ny] * percent[i]) / 100;
		if (mx < 1 || mx > n || my < 1 || my > n) ans += sum;
		else a[mx][my] += sum;
		sand -= sum;
	}
	mx = nx + dx[dir];
	my = ny + dy[dir];
	if (mx < 1 || mx > n || my < 1 || my > n) ans += sand;
	else a[mx][my] += sand;
	a[nx][ny] = 0;
}

void sol() {
	int x = (n + 1) >> 1;
	int y = (n + 1) >> 1;
	int moveCnt = 1;
	int dir = 0;

	while (moveCnt != n) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < moveCnt; j++) {
				sparse(x, y, dir);
				x += dx[dir];
				y += dy[dir];
			}
			dir = (dir + 1) % 4;
		}
		if (++moveCnt == n) {
			for (int i = 0; i < moveCnt; i++) {
				sparse(x, y, dir);
				x += dx[dir];
				y += dy[dir];
			}
		}
	}
	cout << ans;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	input();
	sol();
	return 0;
}
