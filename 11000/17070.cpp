#include<iostream>
using namespace std;

int n, answer = 0;;
int area[16][16];
int dx[3]{ 0,1,1 };
int dy[3]{ 1,1,0 };

void input() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> area[i][j];
		}
	}
}

void dfs(int x, int y, int t) {
	if (x == n - 1 && y == n - 1) {
		++answer;
		return;
	}
	for (int dir = 0; dir < 3; ++dir) {
		if ((dir == 0 && t == 2) || (dir == 2 && t == 0)) continue;
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
		if (area[nx][ny] == 1) continue;
		if (dir == 1 && (area[x + 1][y] == 1 || area[x][y + 1] == 1)) continue;
		dfs(nx, ny, dir);
	}
}

void solution() {
	input();
	dfs(0, 1, 0);
	cout << answer;
}

int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
