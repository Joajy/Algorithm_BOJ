#include<iostream>
#include<queue>
using namespace std;
#define p pair<int, int>

int r, c;
char area[251][251];
bool vis[251][251]{ 0 };
int dx[]{ 0,1,0,-1 };
int dy[]{ 1,0,-1,0 };

void input() {
	cin >> r >> c;
	string s;
	for (int i = 0; i < r; ++i) {
		cin >> s;
		for (int j = 0; j < c; ++j) {
			area[i][j] = s[j];
		}
	}
}

void solution() {
	input();
	int s = 0, w = 0;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (vis[i][j] || area[i][j] == '#') continue;
			int sheep = 0, wolf = 0;
			queue<p> q;
			q.push({ i,j });
			vis[i][j] = 1;
			if (area[i][j] == 'v') ++wolf;
			else if (area[i][j] == 'o') ++sheep;
			while (!q.empty()) {
				p cur = q.front(); q.pop();
				for (int dir = 0; dir < 4; ++dir) {
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];
					if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
					if (vis[nx][ny] || area[nx][ny] == '#') continue;
					if (area[nx][ny] == 'v') ++wolf;
					else if (area[nx][ny] == 'o') ++sheep;
					q.push({ nx,ny });
					vis[nx][ny] = 1;
				}
			}
			if (wolf < sheep) s += sheep;
			else w += wolf;
		}
	}
	cout << s << ' ' << w;
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
