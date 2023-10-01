#include<iostream>
#include<map>
#include<queue>
#define p pair<int, int>
using namespace std;

struct Next {
	int x, y, cost;
	Next() {
		x = y = cost = 0;
	}
	Next(int a, int b, int c) {
		x = a;
		y = b;
		cost = c;
	}
};

int n, m, fuel;
int a[21][21];			//1: 벽
int dx[]{ -1,0,0,1 };	//행 번호 가장 작은, 열 번호 가장 작은 경우의 조건 순서
int dy[]{ 0,-1,1,0 };
Next cur;
map<p, p> ma;

void input() {
	cin >> n >> m >> fuel;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
		}
	}
	//택시 초기 위치
	cin >> cur.x >> cur.y;
	int srcR, srcC, dstR, dstC;
	for (int i = 1; i <= m; ++i) {
		cin >> srcR >> srcC >> dstR >> dstC;
		ma[{srcR, srcC}] = { dstR, dstC };
	}
}

void findNext() {
	queue<Next> q;
	q.push(cur);
	Next tmp(0, 0, 500000);
	bool vis[21][21]{0};
	vis[cur.x][cur.y] = 1;
	while (!q.empty()) {
		Next z = q.front(); q.pop();
		//승객 발견 시 승객 위치 반환
		if (ma[{z.x, z.y}] != make_pair(0, 0)) {
			if (tmp.cost > z.cost) tmp = z;
			if (tmp.cost == z.cost) {
				if (tmp.x > z.x) tmp = z;
				else if (tmp.x == z.x) {
					if (tmp.y > z.y) tmp = z;
				}
			}
		}
		for (int dir = 0; dir < 4; ++dir) {
			int nx = z.x + dx[dir];
			int ny = z.y + dy[dir];
			if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
			if (vis[nx][ny] || a[nx][ny] == 1) continue;
			vis[nx][ny] = 1;
			q.push(Next(nx,ny,z.cost + 1));
		}
	}
	//태울 수 있는 승객을 찾지 못했을 경우 초기 cost인 500001을 가질 예정
	cur = tmp;
	return;
}

void move(p dst) {
	queue<Next> q;
	q.push(cur);
	bool vis[21][21]{ 0 };
	vis[cur.x][cur.y] = 1;
	while (!q.empty()) {
		Next z = q.front(); q.pop();
		if (z.x == dst.first && z.y == dst.second) {
			//도착했으니 위치 비우기
			//a[z.x][z.y] = 0;
			cur = z;
			return;
		}
		for (int dir = 0; dir < 4; ++dir) {
			int nx = z.x + dx[dir];
			int ny = z.y + dy[dir];
			if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
			if (vis[nx][ny] || a[nx][ny] == 1) continue;
			vis[nx][ny] = 1;
			q.push(Next(nx, ny, z.cost + 1));
		}
	}
	cur.cost = -1;
}

void solution() {
	input();
	while (m--) {
		//승객 태우러 가기
		findNext();
		fuel -= cur.cost;
		cur.cost = 0;
		//목적지 지정
		p dst = ma[{ cur.x,cur.y }];
		//탑승했으니 위치 비우기
		ma[{cur.x, cur.y}] = { 0,0 };
		//목적지로 운행
		move(dst);
		fuel -= cur.cost;
		if (fuel < 0 || cur.cost == -1) {
			cout << -1;
			return;
		}
		fuel += (cur.cost << 1);
		cur.cost = 0;
	}
	cout << fuel;
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
