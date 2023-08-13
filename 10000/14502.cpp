#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define p pair<int, int>

int n, m, answer = 64, add = 3;
int area[8][8]{ 0 };
int dx[]{ 0,1,0,-1 };
int dy[]{ 1,0,-1,0 };
queue<p> virus;

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> area[i][j];
			if (area[i][j] == 1) ++add;
			else if (area[i][j] == 2) virus.push({ i,j });
		}
	}
}

void bfs() {
	queue<p> q;
	q = virus;
	bool vis[8][8]{ 0 };
	int ans = 0;
	while (!q.empty()) {
		p cur = q.front(); q.pop();
		++ans;
		for (int dir = 0; dir < 4; ++dir) {
			int x = cur.first + dx[dir];
			int y = cur.second + dy[dir];
			if (x < 0 || y < 0 || x >= n || y >= m) continue;
			if (vis[x][y] || area[x][y] > 0) continue;
			vis[x][y] = 1;
			q.push({ x,y });
		}
	}
	if (answer > ans) answer = ans;
}

void solution() {
	input();
	int sq = n * m;
	for (int i = 0; i < sq - 2; ++i) {
		if (area[i / m][i % m] > 0) continue;
		area[i / m][i % m] = 1;
		for (int j = i + 1; j < sq - 1; ++j) {
			if (area[j / m][j % m] > 0) continue;
			area[j / m][j % m] = 1;
			for (int k = j + 1; k < sq; ++k) {
				if (area[k / m][k % m] > 0) continue;
				area[k / m][k % m] = 1;
				bfs();
				area[k / m][k % m] = 0;
			}
			area[j / m][j % m] = 0;
		}
		area[i / m][i % m] = 0;
	}
	cout << n * m - answer - add;
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
