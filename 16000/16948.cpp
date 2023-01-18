#include<iostream>
#include<cstring>
#include<queue>
#include<utility>
using namespace std;

int area[301][301];
int dx[8]{ -2,-2,0,0,2,2 };
int dy[8]{ -1,1,-2,2,-1,1 };

int main() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n, a, b, c, d;
	memset(area, 0, sizeof(area));
	queue<pair<int, int>> q;
	cin >> n >> a >> b >> c >> d;
	q.push({ a,b });
	area[a][b] = 1;
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		if (cur.first == c && cur.second == d)
			break;
		for (int dir = 0; dir < 6; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || ny < 0 || nx > n || ny > n) continue;
			if (area[nx][ny] != 0) continue;
			area[nx][ny] = area[cur.first][cur.second] + 1;
			q.push({ nx,ny });
		}
	}
	cout << area[c][d] - 1 << '\n';
	return 0;
}
