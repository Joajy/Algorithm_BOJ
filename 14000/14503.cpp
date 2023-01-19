#include<iostream>
#include<stack>
#include<utility>
using namespace std;

int a[51][51];
bool vis[51][51];
int dx[4]{ -1,0,1,0 };
int dy[4]{ 0,1,0,-1 };
#define x first
#define y second

int main() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n, m, answer = 0;
	cin >> n >> m;
	int r, c, d;
	cin >> r >> c >> d;
	for (int i = 0; i < n * m; i++) cin >> a[i / m][i % m];
	stack<pair<int, int>> s;
	s.push({ r,c });
	while (!s.empty()) {
		auto cur = s.top(); s.pop();
		int already = 0;
		if (!vis[cur.x][cur.y]) {
			answer++;
			vis[cur.x][cur.y] = 1;
		}
		for (int dir = d + 3; dir <= d + 12; dir += 3) {
			int nx = cur.x + dx[dir % 4];
			int ny = cur.y + dy[dir % 4];
			if (vis[nx][ny] || a[nx][ny] == 1) {
				already++;
				continue;
			}
			d = dir % 4;
			s.push({ nx,ny });
			break;
		}
		if (already == 4) {
			if (a[cur.x + dx[(d + 2) % 4]][cur.y + dy[(d + 2) % 4]] == 1)
				break;
			s.push({ cur.x + dx[(d + 2) % 4],cur.y + dy[(d + 2) % 4] });
		}
	}
	cout << answer;
	return 0;
}
