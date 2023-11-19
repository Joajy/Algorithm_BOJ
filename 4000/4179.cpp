#include <iostream>
#include <queue>
using namespace std;
#define p pair<int, int>
#define MAX 1001

int r, c, answer = 1e9;
int dx[]{ 0,1,0,-1 };
int dy[]{ 1,0,-1,0 };
char area[MAX][MAX];
int ePath[MAX][MAX];
int fPath[MAX][MAX];
queue<p> q, q2;

void input() {
	cin >> r >> c;
	string s;
	for (int i = 0; i < r; ++i) {
		fill(ePath[i], ePath[i] + c, -1);
		fill(fPath[i], fPath[i] + c, -1);
	}
	for (int i = 0; i < r; ++i) {
		cin >> s;
		for (int j = 0; j < c; ++j) {
			area[i][j] = s[j];
			if (s[j] == 'J') {
				q2.push(p(i, j));
				ePath[i][j] = 0;
			}
			else if (s[j] == 'F') {
				q.push(p(i, j));
				fPath[i][j] = 0;
			}
		}
	}
}

void firePath() {
	while (!q.empty()) {
		p cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; ++dir) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
			if (fPath[nx][ny] >= 0 || area[nx][ny] == '#') continue;
			q.push(p(nx, ny));
			fPath[nx][ny] = fPath[cur.first][cur.second] + 1;
		}
	}
}

bool escapePath() {
	while (!q2.empty()) {
		p cur = q2.front(); q2.pop();
		for (int dir = 0; dir < 4; ++dir) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || ny < 0 || nx >= r || ny >= c) {
				cout << ePath[cur.first][cur.second] + 1;
				return 1;
			}
			if (ePath[nx][ny] >= 0 || area[nx][ny] == '#') continue;
			if (fPath[nx][ny] != -1 && fPath[nx][ny] <= ePath[cur.first][cur.second] + 1) continue;
			q2.push(p(nx, ny));
			ePath[nx][ny] = ePath[cur.first][cur.second] + 1;
		}
	}
	return 0;
}

void solution() {
	input();
	firePath();
	if (!escapePath()) cout << "IMPOSSIBLE";
}

int main(){
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
