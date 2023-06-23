#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
#define p pair<int, int>

int n, m, answer = 0;
char area[50][50];
int ans[50][50]{ 0 };
int dx[4]{ 0,1,0,-1 };
int dy[4]{ 1,0,-1,0 };

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> area[i][j];
		}
	}
}

void init() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			ans[i][j] = 0;
		}
	}
}

void solution() {
	input();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (area[i][j] == 'W') continue;
			bool vis[50][50]{ 0 };
			vis[i][j] = 1;
			init();
			queue<p> q;
			q.push(make_pair(i, j));
			while (!q.empty()) {
				p cur = q.front(); q.pop();
				for (int dir = 0; dir < 4; ++dir) {
					int nx = cur.first + dx[dir];
					int ny = cur.second+ dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (vis[nx][ny] || area[nx][ny] == 'W') continue;
					q.push(make_pair(nx, ny));
					vis[nx][ny] = 1;
					ans[nx][ny] = max(ans[nx][ny], ans[cur.first][cur.second] + 1);
					if (ans[nx][ny] > answer) answer = ans[nx][ny];
				}
			}
		}
	}
	cout << answer;
}

int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
