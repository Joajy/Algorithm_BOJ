#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
#define p pair<int, int>

int n, m, ansCnt = 0, answer = 0;
int area[301][301];
int lazy[301][301];
bool vis[301][301];
int dx[]{ 0,1,0,-1 };
int dy[]{ 1,0,-1,0 };

void input() {
	cin >> n >> m;
	for (int i = 1;i <= n;++i) {
		for (int j = 1;j <= m;++j) {
			cin >> area[i][j];
			if (area[i][j] > 0) ++ansCnt;
		}
	}
}

void calculate() {
	for (int i = 2;i < n;++i) {
		for (int j = 2;j < m;++j) {
			if (area[i][j] == 0) continue;
			for (int dir = 0;dir < 4;++dir) {
				int x = i + dx[dir];
				int y = j + dy[dir];
				if (x < 1 || x > n || y < 1 || y > m) continue;
				if (area[x][y] > 0) continue;
				--lazy[i][j];
			}
		}
	}
	for (int i = 2;i < n;++i) {
		for (int j = 2;j < m;++j) {
			if (area[i][j] == 0) continue;
			if (area[i][j] + lazy[i][j] <= 0) {
				area[i][j] = 0;
				--ansCnt;
			}
			else area[i][j] += lazy[i][j];
		}
	}
}

bool day() {
	memset(vis, 0, sizeof(vis));
	memset(lazy, 0, sizeof(lazy));
	calculate();
	if (ansCnt == 0) return false;
	++answer;
	int cnt = 0;
	for (int i = 2;i < n;++i) {
		for (int j = 2;j < m;++j) {
			if (area[i][j] == 0 || vis[i][j]) continue;
			if (cnt > 0) return false;
			++cnt;
			queue<p> q;
			q.push({ i,j });
			vis[i][j] = 1;
			while (!q.empty()) {
				p cur = q.front(); q.pop();
				for (int dir = 0;dir < 4;++dir) {
					int x = cur.first + dx[dir];
					int y = cur.second + dy[dir];
					if (x < 1 || x > n || y < 1 || y > m) continue;
					if (vis[x][y] || area[x][y] == 0) continue;
					q.push({ x,y });
					vis[x][y] = 1;
				}
			}
		}
	}
	return true;
}

void solution() {
	input();
	while (day()) {
	}
	if (ansCnt == 0) cout << 0;
	else cout << answer;
}

int main() {
	cin.tie(0);  cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
