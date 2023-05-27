#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
#define MAX 101
#define p pair<int, int>
int a[MAX][MAX];
bool vis[MAX][MAX]{ 0 };
int n, m, k;
int dx[]{ 0,1,0,-1 };
int dy[]{ 1,0,-1,0 };
vector<int> answer;

void input() {
	cin >> m >> n >> k;
	int x1, x2, y1, y2;
	for (int i = 0; i < k; ++i) {
		cin >> x1 >> y1 >> x2 >> y2;
		for(int x=x1;x<x2;++x){
			for (int y = y1; y < y2; ++y) {
				vis[y][x] = 1;
			}
		}
	}
}

void solution() {
	input();
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (vis[i][j]) continue;
			vis[i][j] = 1;
			int size = 1;
			queue<p> q;
			q.push(make_pair(i, j));
			while (!q.empty()) {
				p cur = q.front(); q.pop();
				for (int dir = 0; dir < 4; ++dir) {
					int nx = cur.first + dx[dir];
					int ny = cur.second+ dy[dir];
					if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
					if (vis[nx][ny]) continue;
					vis[nx][ny] = 1;
					q.push(make_pair(nx, ny));
					++size;
				}
			}
			if (size != 0) {
				answer.push_back(size);
			}			
		}
	}
	cout << answer.size() << '\n';
	sort(answer.begin(), answer.end());
	for (auto i : answer) {
		cout << i << ' ';
	}
}

int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
