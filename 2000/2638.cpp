#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
#define p pair<int, int>

int n, m, cheese = 0;
int a[101][101];
int copyArr[101][101];
bool vis[101][101];
int dx[]{ 0,1,0,-1 };
int dy[]{ 1,0,-1,0 };

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for(int j=0;j<m;++j){
			cin >> a[i][j];
			copyArr[i][j] = a[i][j];
			if (a[i][j] == 1) ++cheese;
		}
	}
	queue<p> q;
	q.push({ 0,0 });
	a[0][0] = copyArr[0][0] = 2;
	while (!q.empty()) {
		p cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; ++dir) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (a[nx][ny] >= 1) continue;
			q.push({ nx,ny });
			a[nx][ny] = copyArr[nx][ny] = 2;
		}
	}
}

void melting() {
	memset(vis, 0, sizeof(vis));
	queue<p> q;
	q.push({ 0,0 });
	vis[0][0] = 1;
	while (!q.empty()) {
		p cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; ++dir) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (a[nx][ny] == 1 || vis[nx][ny] == 1) continue;
			q.push({ nx,ny });
			vis[nx][ny] = 1;
			a[nx][ny] = copyArr[nx][ny] = 2;
		}
	}
	for (int i = 1; i < n - 1; ++i) {
		for (int j = 1; j < m - 1; ++j) {
			if (a[i][j] != 1) continue;
			int cnt = 0;
			for (int dir = 0; dir < 4; ++dir) {
				int nx = i + dx[dir];
				int ny = j + dy[dir];
				if (a[nx][ny] == 2) ++cnt;
			}
			if (cnt >= 2) {
				copyArr[i][j] = 0;
				--cheese;
			}
			else {
				copyArr[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			a[i][j] = copyArr[i][j];
		}
	}
}

void solution() {
	input();
	int day = 0;
	while (cheese != 0) {
		melting();
		++day;
	}
	cout << day;
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
