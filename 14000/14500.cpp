#include<iostream>
using namespace std;
#define max(a,b) (a > b) ? a : b
#define MAX 501

int dx[4]{ 0,1,0,-1 }, dy[4]{ 1,0,-1,0 };
bool vis[MAX][MAX];
int a[MAX][MAX];
int n, m, ans = 0;

void solution(int x, int y, int cnt, int score) {
	if (cnt == 4) {
		ans = max(ans, score);
		return;
	}

	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 1 || ny < 1 || nx > n || ny > m || vis[nx][ny]) continue;
		vis[nx][ny] = 1;
		solution(nx, ny, cnt + 1, score + a[nx][ny]);
		vis[nx][ny] = 0;
	}

	if (x > 1 && x < n) {
		int sum = a[x - 1][y] + a[x][y] + a[x + 1][y];
		if (y < m) ans = max(ans, sum + a[x][y + 1]);
		if (y > 1) ans = max(ans, sum + a[x][y - 1]);
	}
	if (y > 1 && y < m) {
		int sum = a[x][y - 1] + a[x][y] + a[x][y + 1];
		if (x < n) ans = max(ans, sum + a[x + 1][y]);
		if (x > 1) ans = max(ans, sum + a[x - 1][y]);
	}
}

int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			vis[i][j] = 1;
			solution(i, j, 1, a[i][j]);
			vis[i][j] = 0;
		}
	}
	cout << ans;
	return 0;
}
