#include<iostream>
#include<queue>
using namespace std;
#define p pair<int, int>

int n, maxH = 0;
int area[101][101];
bool height[101];
int dx[]{ 0,1,0,-1 };
int dy[]{ 1,0,-1,0 };

void input() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> area[i][j];
			if (maxH < area[i][j]) maxH = area[i][j];
		}
	}
}

void solution() {
	input();
	int answer = 1;
	for (int h = 1; h <= maxH; ++h) {
		int cnt = 0;
		bool vis[101][101]{ 0 };
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (vis[i][j] || area[i][j] <= h) continue;
				queue<p> q;
				q.push(make_pair(i, j));
				++cnt;
				vis[i][j] = 1;
				while (!q.empty()) {
					p cur = q.front(); q.pop();
					for (int dir = 0; dir < 4; ++dir) {
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];
						if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
						if (vis[nx][ny] || area[nx][ny] <= h) continue;
						vis[nx][ny] = 1;
						q.push(make_pair(nx, ny));
					}
				}
			}
		}
		if (cnt > answer) answer = cnt;
	}
	cout << answer;
}

int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
