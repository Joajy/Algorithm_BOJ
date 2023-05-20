#include<iostream>
using namespace std;

#define MAX 500
int area[MAX][MAX];
int dp[MAX][MAX];
int n, m, answer = 0;
int dx[]{ 0,1,0,-1 };
int dy[]{ 1,0,-1,0 };

void input() {
	cin >> m >> n;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> area[i][j];
			dp[i][j] = -1;
		}
	}
}

int dfs(int x, int y) {
	if (x == m - 1 && y == n - 1) return 1;
	if (dp[x][y] != -1) return dp[x][y];
	dp[x][y] = 0;
	for (int dir = 0; dir < 4; ++dir) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
		if (area[nx][ny] >= area[x][y]) continue;
		dp[x][y] += dfs(nx,ny);
	}
	return dp[x][y];
}

void solution() {
	cout << dfs(0, 0);
}

int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
	input();
	solution();
	return 0;
}
