#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define p pair<int, int>

int n, m, st, answer = 0;
vector<p> edge[1001];
bool vis[1001]{ 0 };

void init() {
	cin >> n >> m;
	int a, b, c;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> c;
		st = a;
		edge[a].push_back(p(c, b));
		edge[b].push_back(p(c, a));
	}
}

void kruskal() {
	priority_queue<p> pq;
	pq.push(p(0, st));
	while (!pq.empty()) {
		p cur = pq.top(); pq.pop();
		if (vis[cur.second]) continue;
		vis[cur.second] = 1;
		answer -= cur.first;
		for (p nxt : edge[cur.second]) {
			if (vis[nxt.second]) continue;
			pq.push(p(-nxt.first, nxt.second));
		}
	}
}

void solution() {
    init();
	kruskal();
	cout << answer;
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
