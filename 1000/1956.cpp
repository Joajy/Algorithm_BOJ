#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 401
#define p pair<int, int>

int v, e, answer = 1e9;
vector<p> edge[MAX];

void init() {
	cin >> v >> e;
	int a, b, c;
	for (int i = 0; i < e; ++i) {
		cin >> a >> b >> c;
		edge[a].push_back({ b,c });
	}
}

void dijkstra(int st) {
	int dist[MAX];
	fill(dist, dist + v + 1, 1e9);
	priority_queue<p> pq;
	pq.push({ 0, st });
	while (!pq.empty()) {
		p cur = pq.top(); pq.pop();
		if (dist[st] != 1e9 && cur.second == st) break;
		if (dist[cur.second] < -cur.first) continue;
		for (p nxt : edge[cur.second]) {
			if (dist[nxt.first] <= -cur.first + nxt.second) continue;
			dist[nxt.first] = -cur.first + nxt.second;
			pq.push({ -dist[nxt.first], nxt.first });
		}
	}
	if (answer > dist[st]) answer = dist[st];
}

void solution() {
	init();
	for (int i = 1; i <= v; ++i) {
		dijkstra(i);
	}
	if (answer == 1e9) cout << -1;
	else cout << answer;
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
