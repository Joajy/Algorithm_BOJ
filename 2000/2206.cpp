#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 2147483647

struct BLOCK {
	int r, c, chance;
};

const int MAX = 1001;
string s;
int n, m;
char map[MAX][MAX];	//map with walls
int a[MAX][MAX][2];	//no chance's dist [][][0], one chance's dist [][][1]
int dx[]{ 0,1,0,-1 };
int dy[]{ 1,0,-1,0 };

void input() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		for (int j = 1; j <= m; j++) {
			map[i][j] = s[j - 1];
			a[i][j][0] = a[i][j][1] = INF;
		}
	}
}

void bfs() {
	queue<BLOCK> q;
	q.push({ 1,1,1 });
	a[1][1][1] = 1;
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.r + dx[dir];
			int ny = cur.c + dy[dir];
			if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
			//벽으로 막혀있지만, 뚫을 기회가 있음
			if (map[nx][ny] == '1' && cur.chance == 1) {
				q.push({ nx,ny,0 });
				a[nx][ny][0] = a[cur.r][cur.c][1] + 1;
			}
			//벽도 없고 간 적도 없음
			if (map[nx][ny] == '0' && a[nx][ny][cur.chance] == INF) {
				q.push({ nx,ny,cur.chance });
				a[nx][ny][cur.chance] = a[cur.r][cur.c][cur.chance] + 1;
			}
		}
	}
}

void solution() {
	input();
	bfs();
	if (a[n][m][0] == INF && a[n][m][1] == INF) a[n][m][0] = -1;
	cout << min(a[n][m][0], a[n][m][1]);
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	solution();
	return 0;
}
