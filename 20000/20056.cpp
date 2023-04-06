#include <iostream>
#include <vector>
using namespace std;
int n, m, k, a, b, c, d, e;
const int MAX = 51;

struct Fireball {
	int x, y, mass, speed, dir;
};

vector<Fireball> area[MAX][MAX];
vector<Fireball> fb;	//r,c,m,s,d

int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

void input() {
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c >> d >> e;
		area[a][b].push_back({ a,b,c,d,e });
		fb.push_back({ a,b,c,d,e });
	}
}

void move() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			area[i][j].clear();
	for (int i = 0; i < fb.size(); i++) {
		int r, c, m, s, di;
		r = fb[i].x, c = fb[i].y, m = fb[i].mass, s = fb[i].speed, di = fb[i].dir;

		int mov = s % n;
		int nx = r + dx[di] * mov;
		int ny = c + dy[di] * mov;
		if (nx > n) nx -= n;
		if (nx < 1) nx += n;
		if (ny > n) ny -= n;
		if (ny < 1) ny += n;

		area[nx][ny].push_back({ nx,ny,m, s, di });
		fb[i].x = nx, fb[i].y = ny;
	}
}

void sum() {
	fb.clear();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (area[i][j].size() == 0) continue;
			if (area[i][j].size() == 1) {
				fb.push_back(area[i][j][0]);
				continue;
			}
			int totalMass = 0, totalSpeed = 0;
			bool even = true, odd = true;
			for (int k = 0; k < area[i][j].size(); k++) {
				totalMass += area[i][j][k].mass;
				totalSpeed += area[i][j][k].speed;
				if (area[i][j][k].dir % 2 == 0) odd = false;
				else even = false;
			}

			totalMass /= 5;
			totalSpeed /= (int)area[i][j].size();

			if (totalMass == 0) continue;

			if (odd || even) {
				for (int dir = 0; dir < 4; dir++) {
					fb.push_back({ i, j, totalMass, totalSpeed, 2 * dir });
				}
			}
			else {
				for (int dir = 0; dir < 4; dir++) {
					fb.push_back({ i, j, totalMass, totalSpeed, 2 * dir + 1 });
				}
			}
		}
	}
}

void sol() {
	input();
	for (int i = 0; i < k; i++) {
		move();
		sum();
	}
	int ans = 0;
	for (int i = 0; i < fb.size(); i++) ans += fb[i].mass;
	cout << ans;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	sol();
	return 0;
}
