#include <iostream>
#include <queue>
using namespace std;
#define p pair<int, int>

int n, m, white = 0, blue = 0;
int dx[]{ 0,1,0,-1 };
int dy[]{ 1,0,-1,0 };
char a[101][101];
bool vis[101][101]{ 0 };

void input() {
	cin >> n >> m;
	string s;
	for (int i = 1; i <= m; ++i) {
		cin >> s;
		for (int j = 1; j <= n; ++j) {
			a[i][j] = s[j - 1];
		}
	}
}

void bfs(int x, int y) {
	queue<p> q;
	q.push({ x,y });
	vis[x][y] = 1;
	int cnt = 0;
	while (!q.empty()) {
		p cur = q.front(); q.pop();
		++cnt;
		for (int dir = 0; dir < 4; ++dir) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 1 || ny < 1 || nx > m || ny > n) continue;
			if (vis[nx][ny] || a[x][y] != a[nx][ny]) continue;
			vis[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}
	if (a[x][y] == 'W') {
		white += cnt * cnt;
	}
	else {
		blue += cnt * cnt;
	}
}

void solution() {
	input();
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (vis[i][j]) continue;
			bfs(i, j);
		}
	}
	cout << white << ' ' << blue;
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
