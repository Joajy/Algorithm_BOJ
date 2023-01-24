#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> v[1001];
int deg[1001], period[1001], result[1001];
int t, n, k, x, y, w, answer;

void init() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> period[i];
		deg[i] = 0;
		result[i] = period[i];
		v[i].clear();
	}
	for (int i = 0; i < k; i++) {
		cin >> x >> y;
		v[x].push_back(y);
		deg[y]++;
	}
	cin >> w;
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> t;
	while(t--) {
		init();
		queue<int> q;
		for (int i = 1; i <= n; i++) {
			if (deg[i] == 0)
				q.push(i);
			result[i] = period[i];
		}
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			for (auto nxt : v[cur]) {
				if (--deg[nxt] == 0)
					q.push(nxt);
				result[nxt] = max(result[nxt], result[cur] + period[nxt]);
			}
		}
		cout << result[w] << '\n';
	}
	return 0;
}
