#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define p pair<int, int>

int n, m;
vector<int> v[200001], add[200001];
int cnt[200001]{ 0 };
bool vis[200001]{ 0 };
queue<p> q;

void input() {
	cin >> n;
	int num;
	for (int i = 1; i <= n; ++i) {
		while (cin >> num) {
			if (num == 0) break;
			v[i].push_back(num);
		}
	}
	cin >> m;
	while (m--) {
		cin >> num;
		q.push({ num, 0 });
		cnt[num] = 0;
		vis[num] = 1;
	}
}

void bfs() {
	while (!q.empty()) {
		int cur = q.front().first;
		int dist = q.front().second; q.pop();
		for (int i : v[cur]) {
			if (cnt[i] > 0 || vis[i]) continue;
			add[i].push_back(cur);
			if (v[i].size() <= add[i].size() * 2) {
				q.push({ i, dist + 1 });
				cnt[i] = dist + 1;
				vis[i] = 1;
			}
		}
	}
}

void solution() {
	input();
	bfs();
	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) cnt[i] = -1;
		cout << cnt[i] << ' ';
	}
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
