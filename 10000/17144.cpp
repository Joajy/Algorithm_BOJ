#include<iostream>
using namespace std;

int r, c, t, answer = 0;
int cleaner;	//x좌표, y좌표는 1로 고정되어있으므로 신경 ㄴ
int a[51][51];
int dx[]{ 0,1,0,-1 };
int dy[]{ 1,0,-1,0 };

void input() {
	cin >> r >> c >> t;
	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= c; ++j) {
			cin >> a[i][j];
			if (a[i][j] == -1) cleaner = i;
		}
	}
	--cleaner;	//위에서부터 시작하기 위함
}

void spread() {
	int tmp[51][51]{ 0 };
	//1. 미세먼지 확산
	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= c; ++j) {
			tmp[i][j] += a[i][j];
			for (int dir = 0; dir < 4; ++dir) {
				int nx = i + dx[dir];
				int ny = j + dy[dir];
				// 인접한 방향에 공기청정기, 혹은 칸이 없으면 확산 ㄴ
				if (nx < 1 || nx > r || ny < 1 || ny > c) continue;
				if (ny == 1 && (nx == cleaner || nx == cleaner + 1)) continue;
				tmp[nx][ny] += a[i][j] / 5;
				tmp[i][j] -= a[i][j] / 5;
			}
		}
	}
	//2. 공기청정기 작동
	//2-1. 위 -> 반시계 방향
	int temp = tmp[cleaner][c], z;
	for (int i = cleaner - 1; i > 1; --i) {
		tmp[i][1] = tmp[i - 1][1];
	}
	for (int i = 1; i < c; ++i) {
		tmp[1][i] = tmp[1][i + 1];
	}
	for (int i = 1; i < cleaner; ++i) {
		tmp[i][c] = tmp[i + 1][c];
	}
	for (int i = c; i > 1; --i) {
		tmp[cleaner][i] = tmp[cleaner][i - 1];
	}
	tmp[cleaner++][2] = 0;
	//2-2. 아래 -> 시계 방향
	//temp = tmp[--cleaner][c];
	for (int i = cleaner + 1; i < r; ++i) {
		tmp[i][1] = tmp[i + 1][1];
	}
	for (int i = 1; i < c; ++i) {
		tmp[r][i] = tmp[r][i + 1];
	}
	for (int i = r; i > cleaner; --i) {
		tmp[i][c] = tmp[i - 1][c];
	}
	for (int i = c; i > 1; --i) {
		tmp[cleaner][i] = tmp[cleaner][i - 1];
	}
	tmp[cleaner--][2] = 0;
	//3. 원래 배열로  copy
	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= c; ++j) {
			a[i][j] = tmp[i][j];
		}
	}
}


void solution() {
	input();
	for (int i = 0; i < t; ++i) {
		spread();
	}
	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= c; ++j) {
			answer += a[i][j];
		}
	}
	cout << answer + 2;
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
