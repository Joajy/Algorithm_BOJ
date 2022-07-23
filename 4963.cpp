#include<iostream>
#include<stack>
#include<utility>
using namespace std;

int land[52][52];
bool vis[52][52];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int tx[4] = { 1, 1, -1, -1 };
int ty[4] = { 1, -1, -1, 1 };

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int w, h;
	while (cin >> w >> h) {
		if (w == 0 && h == 0) break;
		int ans = 0;
		stack<pair<int, int>> s;
		memset(vis, 0, sizeof(vis));
		memset(land, 0, sizeof(land));
		for (int i = 0; i < w * h; i++)
			cin >> land[i / w][i % w];
		for (int i = 0; i < w * h; i++) {
			if (vis[i / w][i % w] == 1 || land[i / w][i % w] != 1) continue;
			s.push({ i / w, i % w });
			ans++;
			while (!s.empty()) {
				pair<int, int> cur = s.top(); s.pop();
				for (int dir = 0; dir < 4; dir++) {
					int x = cur.first + dx[dir];
					int y = cur.second + dy[dir];
					if (x >= h || x < 0 || y >= w || y < 0) continue;
					if (vis[x][y] == 1 || land[x][y] == 0) continue;
					vis[x][y] = 1;
					s.push({ x,y });
				}	
				for (int dir = 0; dir < 4; dir++) {
					int t_x = cur.first + tx[dir];
					int t_y = cur.second + ty[dir];
					if (t_x >= h || t_x < 0 || t_y >= w || t_y < 0) continue;
					if (vis[t_x][t_y] == 1 || land[t_x][t_y] == 0) continue;
					vis[t_x][t_y] = 1;
					s.push({ t_x,t_y });
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}