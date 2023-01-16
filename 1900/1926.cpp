#include<iostream>
#include<queue>
#include<utility>
using namespace std;

bool vis[501][501];
int pic[501][501];
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int area = 0, cnt = 0;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n * m; i++)
		cin >> pic[i / m][i % m];

	for (int i = 0; i < n * m; i++) {
		queue<pair<int, int>> q;
		if (vis[i / m][i % m] || pic[i / m][i % m] != 1) continue;
		int cur_area = 0;
		vis[i / m][i % m] = 1;
		q.push({ i / m,i % m });
		while (!q.empty()) {
			pair<int, int> cur = q.front();
			q.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.first + dx[dir];
				int ny = cur.second + dy[dir];
				if (nx >= n || ny >= m || nx < 0 || ny < 0) continue;
				if (vis[nx][ny] == 1 || pic[nx][ny] != 1) continue;
				vis[nx][ny] = 1;
				q.push({nx,ny});
			}
			cur_area++;
		}
		cnt++;
		area = max(area, cur_area);
	}
	cout << cnt << '\n' << area;
	return 0;
}
