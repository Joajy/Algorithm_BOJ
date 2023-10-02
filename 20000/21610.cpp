#include<iostream>
using namespace std;

int n, m;
int a[51][51];			//맨 왼쪽과 맨 오른쪽은 연결되어있음, 위 아래도 마찬가지
bool cloud[51][51]{ 0 };
//1부터 시작하므로 0 ~ 7로 구성(8,1,2,3,4,5,6,7) %8 기준
//대각선은 2,4,6,8(0)임. 참고
int dx[]{ 1,0,-1,-1,-1,0,1,1 };
int dy[]{ -1,-1,-1,0,1,1,1,0 };

void input() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
		}
	}
	cloud[n][1] = cloud[n][2] = 1;
	cloud[n - 1][1] = cloud[n - 1][2] = 1;
}

void moveCloud(int d, int s) {
	bool tmp[51][51]{ 0 };
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (cloud[i][j]) {
				int x = i + dx[d] * s;
				int y = j + dy[d] * s;
				if (x < 1) x += n;
				else if (x > n) x -= n;
				if (y < 1) y += n;
				else if (y > n) y -= n;
				tmp[x][y] = 1;
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cloud[i][j] = tmp[i][j];
		}
	}
}

void getRain() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (cloud[i][j]) {
				++a[i][j];
			}
		}
	}
}

void magic() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (cloud[i][j] == 0) continue;
			//구름이 생긴 칸만 확인
			int cnt = 0;
			for (int dir = 0; dir <= 6; dir+=2) {
				int x = i + dx[dir];
				int y = j + dy[dir];
				if (x < 1 || y < 1 || x > n || y > n) continue;
				if (a[x][y] > 0) ++cnt;
			}
			a[i][j] += cnt;
		}
	}
}

void makeCloud() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (a[i][j] >= 2 && cloud[i][j] == 0) {
				cloud[i][j] = 1;
				a[i][j] -= 2;
			}
			else {
				cloud[i][j] = 0;
			}
		}
	}
}

void solution() {
	input();
	int d, s;
	for (int i = 0; i < m; ++i) {
		cin >> d >> s;
		if (d == 8) d = 0;
		s %= n;
		if (s == 0) s = n;
		//1
		moveCloud(d, s);
		//2
		getRain();
		//4
		magic();
		//3 && 5
		makeCloud();
	}
	int answer = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			answer += a[i][j];
		}
	}
	cout << answer;
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
