#include<iostream>
#include<cstring>
using namespace std;

//장애물: * , 빈칸: .
int n, m, answer, cnt;
string area[31];
bool vis[31][31]{ 0 };
int dx[]{ -1,1,0,0 };
int dy[]{ 0,0,1,-1 };

void input() {
	for (int i = 0; i < n; ++i) {
		cin >> area[i];
		for (int j = 0; j < m; ++j) {
			if (area[i][j] == '*') {
				vis[i][j] = 1;
				++cnt;
			}
		}
	}
}

void rec(int x, int y, int time, int cnt, int d) {
	if (answer <= time) {
		return;
	}
	if (cnt == n * m) {
		if (answer > time) answer = time;
		return;
	}
	int nx = x + dx[d];
	int ny = y + dy[d];
	if (nx >= 0 && ny >= 0 && nx < n && ny < m && !vis[nx][ny]) {
		vis[nx][ny] = 1;
		rec(nx, ny, time, cnt + 1, d);
		vis[nx][ny] = 0;
		return;
	}
	for (int dir = 0; dir < 4; ++dir) {
		if (d == dir) continue;
		nx = x + dx[dir];
		ny = y + dy[dir];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
		if (vis[nx][ny]) continue;
		vis[nx][ny] = 1;
		//방향 같으면 시간 그대로
		rec(nx, ny, time + 1, cnt + 1, dir);
		vis[nx][ny] = 0;
	}
}

void solution() {
	int caseCnt = 1;
	while (cin >> n >> m) {
		memset(vis, 0, sizeof(vis));
		//init
		answer = 1e9;
		cnt = 0;
		input();
		//move
        if (n * m == cnt + 1) {
			cout << "Case " << caseCnt++ << ": " << 0 << '\n';
			continue;
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				//구조물에서 시작하지 않음
				if (vis[i][j]) continue;
				vis[i][j] = 1;
				for (int dir = 0; dir < 4; ++dir) {
					rec(i, j, 1, cnt + 1, dir);
				}
				vis[i][j] = 0;
			}
		}
		if (answer == 1e9) answer = -1;
		cout << "Case " << caseCnt++ << ": " << answer << '\n';
	}
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
