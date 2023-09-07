#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define p pair<int, int>

int n, m, maxCnt = -1;
bool vis[10001];
vector<int> v[10001];
vector<int> answer;

void input() {
	cin >> n >> m;
	int a, b;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		v[b].push_back(a);
	}
}

void bfs(int cur) {
	queue<int> q;
	q.push(cur);
	vis[cur] = 1;
	int curCnt = 0;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int nxt : v[cur]) {
			if (vis[nxt]) continue;
			++curCnt;
			vis[nxt] = 1;
			q.push(nxt);
		}
	}
	if (maxCnt <= curCnt) {
		if (maxCnt < curCnt) {
			answer.clear();
			maxCnt = curCnt;
		}
		answer.push_back(cur);
	}
}

void solution() {
	input();
	for (int i = 1; i <= n; ++i) {
		memset(vis, 0, sizeof(vis));
		bfs(i);
	}
	sort(answer.begin(), answer.end());
	for (int i : answer) {
		cout << i << ' ';
	}
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
