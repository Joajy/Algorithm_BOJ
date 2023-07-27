#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define p pair<int, int>
#define INF 987654321

int n, e, v1, v2;
int dist[801];
vector<p> v[801];

void dijkstra(int st) {
	for (int i = 1; i <= n; ++i) {
		dist[i] = INF;
	}
	priority_queue<p> pq;
	pq.push({ 0, st });
	dist[st] = 0;
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (dist[cur] < cost) continue;
		for (auto i : v[cur]) {
			int nxt = i.first;
			int nxtCost = i.second;
			if (dist[nxt] > cost + nxtCost) {
				dist[nxt] = cost + nxtCost;
				pq.push({ -dist[nxt], nxt });
			}
		}
	}
}

void input() {
	cin >> n >> e;
	int a, b, c;
	for (int i = 0; i < e; ++i) {
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	cin >> v1 >> v2;
}


int solution() {
	input();
	dijkstra(1);
	int s_v1 = dist[v1];
	int s_v2 = dist[v2];
	dijkstra(v1);
	int v1_v2 = dist[v2];
	int v1_n = dist[n];
	dijkstra(v2);
	int v2_n = dist[n];
	int answer = min(INF, s_v1 + v1_v2 + v2_n);
	answer = min(answer, s_v2 + v1_v2 + v1_n);
	if (v1_v2 == INF || answer == INF) return -1;
	return answer;
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	cout << solution();
	return 0;
}
