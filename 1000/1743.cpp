#include <iostream>
#include <queue>
using namespace std;
#define p pair<int, int>

int n, m, k, maxSize = 0;

int area[101][101];
bool vis[101][101]{ 0 };
int dx[]{ 0,1,0,-1 };
int dy[]{ 1,0,-1,0 };

void input() {
	cin >> n >> m >> k;
	int a, b;
	for (int i = 0; i < k; ++i) {
		cin >> a >> b;
		area[a][b] = 1;
	}
}

void bfs(int x, int y) {
	queue<p> q;
	q.push({ x,y });
	vis[x][y] = 1;
	int curSize = 0;
	while (!q.empty()) {
		p cur = q.front(); q.pop();
		++curSize;
		for (int dir = 0; dir < 4; ++dir) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 1 || nx > 100 || ny < 1 || ny > 100) continue;
			if (vis[nx][ny] || area[nx][ny] == 0) continue;
			vis[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}
	if (maxSize < curSize) maxSize = curSize;
}

void solution() {
	input();
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (vis[i][j] || area[i][j] == 0) continue;
			bfs(i, j);
		}
	}
	cout << maxSize;
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
