#include<iostream>
#include<queue>
using namespace std;

int t, n, m, w;
int indeg[1001], cost[1001], dist[1001];
vector<int> v[1001];

void input() {
	cin >> n >> m;
	int a, b;
	for (int i = 1; i <= n; ++i) {
		cin >> cost[i];
		indeg[i] = 0;
		dist[i] = cost[i];
		v[i].clear();
	}
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		v[a].push_back(b);
		++indeg[b];
	}
	cin >> w;
}

void solution() {
	input();
	queue<int> q;
	for (int i = 1; i <= n; ++i) {
		if (indeg[i] == 0) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int nxt : v[cur]) {
			if (--indeg[nxt] == 0) {
				q.push(nxt);
			}
			dist[nxt] = max(dist[nxt], dist[cur] + cost[nxt]);
		}
	}
	cout << dist[w] << '\n';
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		solution();
	}
	return 0;
}
