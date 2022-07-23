#include<iostream>
#include<queue>
#include<utility>
#include<cstring>
using namespace std;

int land[52][52];
bool vis[52][52];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

#define X first
#define Y second
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int t, n, m, k;
	cin >> t;
	for (int i = 0; i < t; i++) {
		memset(vis, 0, sizeof(vis));
		memset(land, 0, sizeof(land));
		int ans = 0;
		cin >> m >> n >> k;
		queue<pair<int, int>> q;
		for (int j = 0; j < k; j++) {
			int a, b;
			cin >> a >> b;
			land[a][b] = 1;
		}
		//searching each location during rounding k * m
		for (int k = 0; k < m * n; k++) {
			//if land[a][b] is not 1 or visited area, go to the next area after continue
			if (land[k / n][k % n] != 1 || vis[k / n][k % n] == 1) continue;
			ans++;
			q.push({ k / n, k % n });
			while (!q.empty()) {
				pair<int, int> cur = q.front(); q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int x = cur.X + dx[dir];
					int y = cur.Y + dy[dir];
					if (x >= m || x < 0 || y >= n || y < 0) continue;
					if (land[x][y] != 1 || vis[x][y] == 1) continue;
					q.push({ x,y });
					vis[x][y] = 1;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}