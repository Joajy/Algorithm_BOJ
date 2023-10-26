#include<iostream>
using namespace std;

int n, answer = 0;
int area[501][501];
int dp[501][501];
int dx[]{ 0,1,0,-1 };
int dy[]{ 1,0,-1,0 };

void input() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> area[i][j];
		}
	}
}

void dfs(int x, int y) {
	for (int dir = 0; dir < 4; ++dir) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
		if (area[x][y] >= area[nx][ny]) continue;
		if(dp[nx][ny] == 0) dfs(nx, ny);
		if (dp[nx][ny] + 1 <= dp[x][y]) continue;
		dp[x][y] = dp[nx][ny] + 1;
	}
    if(answer < dp[x][y]) answer = dp[x][y];
}

void solution() {
	input();
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
            if(dp[i][j] != 0) continue;
			dfs(i, j);
		}
	}
	cout << answer + 1;
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
