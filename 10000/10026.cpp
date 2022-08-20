#include<iostream>
#include<queue>
#include<utility>
#include<cstring>
using namespace std;

char pic[112][102]{ 0 };
bool vis[102][102]{ 0 };
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

#define X first
#define Y second

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, ans1 = 0, ans2 = 0;
	cin >> n;
	queue<pair<int, int>> q;
	for (int i = 0; i < n * n; i++)
		cin >> pic[i / n][i % n];
	//this is for man who hasn't weak of r&g color
	for (int k = 0; k < n * n; k++) {
		//if already visited, calculating another area after continue
		if (vis[k / n][k % n] == 1) continue;
		ans1++;
		q.push({ k / n, k % n });
		while (!q.empty()) {
			pair<int, int> cur = q.front(); q.pop();
			for (int dir = 0; dir < 4; dir++) {
				int x = cur.X + dx[dir];
				int y = cur.Y + dy[dir];
				if (x >= n || x < 0 || y >= n || y < 0) continue;
				if (pic[x][y] != pic[cur.X][cur.Y] || vis[x][y] == 1) continue;
				q.push({ x,y });
				vis[x][y] = 1;
			}
		}
	}
	memset(vis, 0, sizeof(vis));
	//this is for man who has weak of r&g color
	for (int k = 0; k < n * n; k++) {
		//if already visited, calculating another area after continue
		if (vis[k / n][k % n] == 1) continue;
		ans2++;
		q.push({ k / n, k % n });
		while (!q.empty()) {
			pair<int, int> cur = q.front(); q.pop();
			for (int dir = 0; dir < 4; dir++) {
				int x = cur.X + dx[dir];
				int y = cur.Y + dy[dir];
				if (x >= n || x < 0 || y >= n || y < 0) continue;
				//if not equal and don't hold next condition, or already visited
				if ((pic[x][y] != pic[cur.X][cur.Y] &&
					(!(pic[x][y] == 'R' && pic[cur.X][cur.Y] == 'G') &&
					 !(pic[x][y] == 'G' && pic[cur.X][cur.Y] == 'R')))
					|| vis[x][y] == 1) continue;
				q.push({ x,y });
				vis[x][y] = 1;
			}
		}
	}
	cout << ans1 << ' ' << ans2;
	return 0;
}
