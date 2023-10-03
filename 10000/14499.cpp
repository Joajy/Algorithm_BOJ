#include<iostream>
using namespace std;

int n, m, x, y, k;
int a[21][21];
int dx[]{ 0,0,-1,1 };
int dy[]{ 1,-1,0,0 };
//r, c(가로, 세로)는 맨 위, 맨 아래 칸을 공유한다.
//정보 변경 시 둘 다 변경, 이외에는 각 경우에서 변경
int r[4]{ 0 };
int c[4]{ 0 };

void input() {
	cin >> n >> m >> x >> y >> k;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j];
		}
	}
	++x; ++y;
}

/*
	true: 이동
	false: 바깥으로 이동시키려 하는 경우
*/
bool moveDice(int dir) {
	int nx = x + dx[dir];
	int ny = y + dy[dir];
	if (nx < 1 || ny < 1 || nx > n || ny > m) return false;
	x = nx;
	y = ny;
	int written = a[x][y];	//0이면 주사위 값에서 복사됨, 아니면 칸 값이 주사위로 옮겨지고 칸 0됨
	int tmpR[4], tmpC[4];
	switch (dir) {
	case 0:
		for (int i = 0; i < 4; ++i) {
			tmpC[i] = c[(i + 3) % 4];
		}
		for (int i = 0; i < 4; i += 2) {
			r[i] = tmpC[i];
		}
		for (int i = 0; i < 4; ++i) {
			c[i] = tmpC[i];
		}
		break;
	case 1:
		for (int i = 0; i < 4; ++i) {
			tmpC[i] = c[(i + 1) % 4];
		}
		for (int i = 0; i < 4; i += 2) {
			r[i] = tmpC[i];
		}
		for (int i = 0; i < 4; ++i) {
			c[i] = tmpC[i];
		}
		break;
	case 2:
		for (int i = 0; i < 4; ++i) {
			tmpR[i] = r[(i + 1) % 4];
		}
		for (int i = 0; i < 4; i += 2) {
			c[i] = tmpR[i];
		}
		for (int i = 0; i < 4; ++i) {
			r[i] = tmpR[i];
		}
		break;
	case 3:
		for (int i = 0; i < 4; ++i) {
			tmpR[i] = r[(i + 3) % 4];
		}
		for (int i = 0; i < 4; i+=2) {
			c[i] = tmpR[i];
		}
		for (int i = 0; i < 4; ++i) {
			r[i] = tmpR[i];
		}
	}
	if (written == 0) {
		a[x][y] = c[2];
	}
	else {		//written > 0
		c[2] = r[2] = a[x][y];
		a[x][y] = 0;
	}
    return true;
}

void solution() {
	input();
	int cmd;	//1 동, 2 서, 3 북, 4 남
	for (int i = 0; i < k; ++i) {
		cin >> cmd;
		if(!moveDice(--cmd)) continue;
		cout << r[0] << '\n';
	}
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
