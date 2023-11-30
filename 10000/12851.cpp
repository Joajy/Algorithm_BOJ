#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define p pair<int, int>

int n, k, answer = 0;
p dp[100001];

void input() {
	cin >> n >> k;
	for (int i = 0; i <= 100000; ++i) {
		dp[i].first = 1e9;
	}
	dp[n] = p(0, 0);
}

void bfs() {
	queue<int> q;
	q.push(n);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		int dt[]{ cur - 1,cur + 1,cur << 1 };
		for (int i = 0; i < 3; ++i) {
			int nt = dt[i];
			if (nt < 0 || nt > 100000) continue;
			if (dp[nt].first < dp[cur].first + 1) continue;
			if (nt == k) ++dp[k].second;
			dp[nt].first = dp[cur].first + 1;
			q.push(nt);
		}
	}
}

void solve() {
	input();
	if (k == 0) {
		cout << n << '\n' << 1;
		return;
	}
	if (n == k) {
		cout << 0 << '\n' << 1;
		return;
	}
	bfs();
	cout << dp[k].first << '\n' << dp[k].second;
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solve();
	return 0;
}
