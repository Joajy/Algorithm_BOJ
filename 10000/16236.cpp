#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
#define p pair<int, int>
#define X first
#define Y second
#define MAX 21
#define INF 2147482647

int n;
int a[MAX][MAX];
int dx[]{ 0,1,0,-1 };
int dy[]{ 1,0,-1,0 };
int eatCnt = 0, sharkSize = 2;
int ans = 0;
p cur;

struct FISH {
	int Size, r, c;
};

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 9) {
				cur = { i,j };
				a[i][j] = 0;
			}
		}
	}
}

bool move() {
	bool vis[MAX][MAX]{ 0 };
	int tmp[MAX][MAX]{ 0 };
	fill(&tmp[0][0], &tmp[MAX - 1][MAX - 1], INF);
	vector<FISH> fish;
	queue<p> q;
	q.push(cur);
	tmp[cur.X][cur.Y] = 0;
	while (!q.empty()) {		p pos = q.front(); q.pop();		for (int dir = 0; dir < 4; dir++) {			int nx = pos.X + dx[dir];			int ny = pos.Y + dy[dir];			if (nx >= n || nx < 0 || ny >= n || ny < 0) continue;			if (a[nx][ny] > sharkSize) continue;			if (tmp[nx][ny] != INF) continue;			tmp[nx][ny] = tmp[pos.X][pos.Y] + 1;			q.push({ nx,ny });			if (a[nx][ny] < sharkSize && a[nx][ny] > 0) fish.push_back({ a[nx][ny] , nx, ny });		}	}
	if (fish.size() == 0) return false;
	auto pray = fish[0];
	for (int i = 1; i < fish.size(); i++) {
		int distP = tmp[pray.r][pray.c];
		int distF = tmp[fish[i].r][fish[i].c];
		if (distP <= distF) {
			if (distP < distF) continue;
			if (pray.r <= fish[i].r) {
				if (pray.r < fish[i].r) continue;
				if (pray.c <= fish[i].c) continue;
			}
		}
		pray = fish[i];
	}
	a[pray.r][pray.c] = 0;
	if (sharkSize == ++eatCnt) {
		eatCnt = 0;
		sharkSize++;
	}
	ans += tmp[pray.r][pray.c];
	cur = { pray.r, pray.c };
	return true;
}

void solution() {
	input();
	while (move());
	cout << ans;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	solution();
	return 0;
}
