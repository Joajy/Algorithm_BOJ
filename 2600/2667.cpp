#include<iostream>
#include<queue>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;

#define X first
#define Y second

int map[26][26];
bool vis[26][26];
int dx[4]{ 0,1,0,-1 };
int dy[4]{ 1,0,-1,0 };

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++)
			map[i][j] = s[j];
	}
	vector<int> v;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vis[i][j] == 1 || map[i][j] == '0') continue;
			int cnt = 1;
			queue<pair<int, int>> q;
			q.push({ i,j });
			vis[i][j] = 1;
			ans++;
			while (!q.empty()) {
				pair<int, int> cur = q.front(); q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int x = cur.X + dx[dir];
					int y = cur.Y + dy[dir];
					if (x >= n || x < 0 || y >= n || y < 0) continue;
					if (map[x][y] == '0' || vis[x][y] == 1) continue;
					q.push({ x,y });
					vis[x][y] = 1;
					cnt++;
				}
			}
			v.push_back(cnt);
		}
	}
	sort(v.begin(), v.end());
	cout << ans << '\n';
	for (int i = 0; i < ans; i++)
		cout << v.at(i) << '\n';
	return 0;
}
