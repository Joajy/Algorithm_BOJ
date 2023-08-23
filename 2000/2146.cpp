#include<iostream>
#include<queue>
using namespace std;
#define p pair<int, int>
int n, answer = 2e9;
int area[101][101];
int color[101][101];
int dx[]{ 0,1,0,-1 };
int dy[]{ 1,0,-1,0 };

int min(int a, int b) {
	if (a < b) return a;
	return b;
}

int abs(int a) {
	if (a > 0) return a;
	return -a;
}

void input() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> area[i][j];
		}
	}
}

void distribute() {
	int cnt = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (area[i][j] == 0 || color[i][j] != 0) continue;
			queue<p> q;
			q.push({ i,j });
			color[i][j] = cnt;
			while (!q.empty()) {
				p cur = q.front(); q.pop();
				for (int dir = 0; dir < 4; ++dir) {
					int x = cur.first + dx[dir];
					int y = cur.second + dy[dir];
					if (x < 1 || y < 1 || x > n || y > n) continue;
					if (color[x][y] != 0 || area[x][y] == 0) continue;
					color[x][y] = cnt;
					q.push({ x,y });
				}
			}
			++cnt;
		}
	}
}

void bfs(int x, int y) {
	queue<p> q;
	q.push({ x,y });
	bool vis[101][101]{ 0 };
	vis[x][y] = 1;
	while (!q.empty()) {
		p cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; ++dir) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
			int a = color[nx][ny], b = color[x][y];
			if(a > 0 && b > 0 && a != b){
				answer = min(answer, (abs(nx - x) + abs(ny - y) - 1));
				return;
			}
			if (area[nx][ny] == 1 || vis[nx][ny]) continue;
			q.push({ nx,ny });
			vis[nx][ny] = 1;
		}
	}
}

void solution() {
	input();
	distribute();
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (area[i][j] == 0) continue;
			bfs(i, j);
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
