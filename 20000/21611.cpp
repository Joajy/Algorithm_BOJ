#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

const int MAX = 50;
int block = 0, score = 0;
int n, m;
int a[MAX][MAX];
int dx[]{ -1,1,0,0 };
int dy[]{ 0,0,-1,1 };
int cx[]{ 0,1,0,-1 };
int cy[]{ -1,0,1,0 };
vector<int> ball;

void magic(int d, int s) {
	for (int i = 1; i <= s; i++) {
		int nx = n / 2 + n % 2 + i * dx[d];
		int ny = n / 2 + +n % 2 + i * dy[d];
		if (a[nx][ny] == 0) continue;
		a[nx][ny] = 0;
		block--;
	}
}

void input() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			if (a[i][j] > 0) block++;
		}
	}
}

//구슬 폭발 with remove function
void explode() {
	bool check = true;
	while (check) {
		vector<int> tmp;
		int idx = 0;
		check = false;
		for (int i = 0; i < ball.size(); i++) {
			idx = i;
			while (idx < ball.size() && ball[idx] == ball[i]) idx++;
			if (idx - i >= 4) {
				score += ball[i] * (idx - i);
				check = true;
			}
			else {
				for (int j = i; j < idx; j++) tmp.push_back(ball[i]);
			}
			i = idx - 1;
		}
		ball = tmp;
	}
}

//달팽이 회전
void saveBall() {
	ball.clear();
	int dir = 0;
	int moveCnt = 1;
	int x = n / 2 + n % 2, y = n / 2 + n % 2;
	int cnt = 0;
	while (block != cnt) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < moveCnt; j++) {
				x = x + cx[dir];
				y = y + cy[dir];
				if (a[x][y] == 0) continue;
				ball.push_back(a[x][y]);
				if (block == ++cnt) return;
			}
			dir = (dir + 1) % 4;
		}
		moveCnt++;
	}
}

void updateMap() {
	int cnt = 0;
	int x = n / 2 + n % 2, y = n / 2 + n % 2;
	int moveCnt = 1, dir = 0;
	while (cnt != ball.size()) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < moveCnt; j++) {
				x = x + cx[dir];
				y = y + cy[dir];
				a[x][y] = ball[cnt++];
				if (cnt == ball.size()) return;
			}
			dir = (dir + 1) % 4;
		}
		moveCnt++;
	}
}

void changeBall() {
	vector<int> tmp;
	int idx;
	for (int i = 0; i < ball.size(); i++) {
		if ((int)tmp.size() >= n * n) break;
		idx = i;
		while (idx < ball.size() && ball[idx] == ball[i]) idx++;
		int a = (idx - i);
		int b = ball[i];
		tmp.push_back(a);
		tmp.push_back(b);
		i = idx - 1;
	}
    while(tmp.size() >= n * n) tmp.pop_back();
	ball = tmp;
	block = ball.size();
}

void solve() {
	int d, s;
	for (int i = 0; i < m; i++) {
		cin >> d >> s;
		magic(d - 1, s);
		saveBall();
		explode();
		changeBall();
		updateMap();
	}
	cout << score;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	input();
	solve();
	return 0;
}
