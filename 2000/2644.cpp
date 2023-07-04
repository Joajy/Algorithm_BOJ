#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define p pair<int, int>

int n, m, st, en, answer = 101;
vector<int> a[101];
bool vis[101];

void input() {
	cin >> n >> st >> en >> m;
	int x, y;
	for (int i = 0; i < m; ++i) {
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
}

void solution() {
	input();
	queue<p> q;
	q.push(make_pair(st, 0));
	while (!q.empty()) {
		p cur = q.front(); q.pop();
		if (vis[cur.first]) continue;
		vis[cur.first] = 1;
		if (cur.first == en && answer > cur.second) {
			answer = cur.second;
			continue;
		}
		for (auto i : a[cur.first]) {
			if (vis[i]) continue;
			q.push(make_pair(i, cur.second + 1));
		}
		for (auto i : a[cur.first]) {
			if (vis[i]) continue;
			q.push(make_pair(i, cur.second + 1));
		}
	}
	if (answer == 101) {
		cout << -1;
		return;
	}
	cout << answer;
}

int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
