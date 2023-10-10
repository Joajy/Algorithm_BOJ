#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
#define p pair<int, int>

int r, c;
char area[51][51];
int water[51][51]{ 0 };
int run[51][51]{ 0 };
int dx[]{ 0,1,0,-1 };
int dy[]{ 1,0,-1,0 };
p st, en;

void input() {
	cin >> r >> c;
	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= c; ++j) {
			cin >> area[i][j];
			if (area[i][j] == 'S') {
				st = { i,j };
			}
			else if (area[i][j] == 'D') {
				en = { i,j };
				run[i][j] = -1;
			}
		}
	}
}

void waterSlide() {
	bool vis[51][51]{ 0 };
	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= c; ++j) {
			if (vis[i][j] || area[i][j] != '*') continue;
			water[i][j] = 0;
			queue<p> q;
			q.push({ i,j });
			vis[i][j] = 1;
			while (!q.empty()) {
				p cur = q.front(); q.pop();
				for (int dir = 0; dir < 4; ++dir) {
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];
					if (nx < 1 || ny < 1 || nx > r || ny > c) continue;
					if (vis[nx][ny] || area[nx][ny] == 'X') continue;
					if (nx == en.first && ny == en.second) continue;
					q.push({ nx,ny });
					vis[nx][ny] = 1;
					water[nx][ny] = water[cur.first][cur.second] + 1;
				}
			}

		}
	}
}

void runBaby() {
	queue<p> q;
	q.push(st);
	bool vis[51][51]{ 0 };
	run[st.first][st.second] = 0;
	vis[st.first][st.second] = 1;
	while (!q.empty()) {
		p cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; ++dir) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 1 || ny < 1 || nx > r || ny > c) continue;
			if (vis[nx][ny] || area[nx][ny] == 'X') continue;
			if (nx == en.first && ny == en.second) {
				run[en.first][en.second] = run[cur.first][cur.second] + 1;
				cout << run[en.first][en.second];
				return;
			}
			if (water[nx][ny] != -1 && water[nx][ny] <= run[cur.first][cur.second] + 1) continue;
			q.push({ nx,ny });
			vis[nx][ny] = 1;
			run[nx][ny] = run[cur.first][cur.second] + 1;
		}
	}
}

void solution() {
	input();
	memset(water, -1, sizeof(water));
	memset(run, -1, sizeof(run));
	waterSlide();
	runBaby();
	if (run[en.first][en.second] == -1) {
		cout << "KAKTUS";
		return;
	}
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
