#include<iostream>
#include<queue>
using namespace std;
#define p pair<int, int>
#define INF 987654321

int n, m;
int dist[101][101]{ 0 };
int board[101][101];
int dx[4]{ 0,1,0,-1 };
int dy[4]{ 1,0,-1,0 };

void dijkstra() {
	priority_queue<p> q;
	q.push({ 1, 1 });
	dist[1][1] = 0;
	while (!q.empty()) {
		int x = q.top().first;
		int y = q.top().second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 1 || nx > m || ny < 1 || ny > n) continue;
			if (dist[nx][ny] <= dist[x][y] + board[nx][ny]) continue;
			dist[nx][ny] = dist[x][y] + board[nx][ny];
			q.push({ nx,ny });
		}
	}
}

void input() {
	cin >> n >> m;
	string s;
	for (int i = 1; i <= m; ++i) {
		cin >> s;
		for (int j = 1; j <= n; ++j) {
			board[i][j] = s[j - 1] - '0';
			dist[i][j] = INF;
		}
	}
}

void solution() {
	input();
	dijkstra();
	cout << dist[m][n];
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
