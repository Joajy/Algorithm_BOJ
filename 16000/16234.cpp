#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;

#define MAX 50
#define p pair<int, int>
int n, l, r;
int a[MAX][MAX];
int dx[]{ 0,1,0,-1 };
int dy[]{ 1,0,-1,0 };

void input() {
	cin >> n >> l >> r;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j];
		}
	}
}

int solution() {
	int day = 0;
	while (1) {
		int count = 0;
		bool vis[MAX][MAX]{ 0 };
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (vis[i][j]) continue;
				int sum = 0;
				vector<p> countryList;
				queue<p> q;
				q.push(make_pair(i, j));
				countryList.push_back(make_pair(i, j));
				vis[i][j] = 1;
				while (!q.empty()) {
					p cur = q.front(); q.pop();
					sum += a[cur.first][cur.second];
					for (int dir = 0; dir < 4; ++dir) {
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];
						if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
						if (vis[nx][ny]) continue;
						int dif = abs(a[nx][ny] - a[cur.first][cur.second]);
						if (dif < l || dif > r) continue;
						vis[nx][ny] = 1;
						q.push(make_pair(nx, ny));
						countryList.push_back(make_pair(nx,ny));
					}
				}
				int Size = countryList.size();
				if (Size > 1) ++count;
				for (int k = 0; k < Size; ++k) {
					a[countryList[k].first][countryList[k].second] = sum / Size;
				}
			}
		}
		if (count == 0) break;
		++day;
	}
	return day;
}

int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
	input();
	cout << solution();
	return 0;
}
