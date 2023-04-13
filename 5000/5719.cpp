#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define pa pair<int, int>
#define INF 2147483647
#define MAX 501
#define DIST first
#define NODE second

vector<pa> a[MAX];	//DIST, NODE
vector<pa> minDist[MAX];	//DIST, NODE
bool vis[MAX][MAX];
int n, m, s, d, u, v, p;

bool input() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) vis[i][j] = 0;
		minDist[i].clear();
		a[i].clear();
	}
	cin >> n >> m;
	if (n == 0 && m == 0) return false;
	cin >> s >> d;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> p;
		a[u].push_back({ p,v });
	}
	return true;
}

int dijkstra() {
	int dist[MAX];
	priority_queue<pa> pq;
	pq.push({0, s});
	for (int i = 0; i < MAX; i++)dist[i] = INF;
	dist[s] = 0;
	while (!pq.empty()) {
		int curDist = -pq.top().first;
		int curNode = pq.top().second;
		pq.pop();
		if (dist[curNode] < curDist) continue;
		for (auto i : a[curNode]) {
			int nxtDist = curDist + i.DIST;
			int nxtNode = i.NODE;
			if (i.DIST == -1) continue;
			if (nxtDist < dist[nxtNode]) {
				dist[nxtNode] = nxtDist;
				pq.push({ -nxtDist, nxtNode });
				minDist[nxtNode].clear();
				minDist[nxtNode].push_back({ nxtDist, curNode });
			}
			else if (nxtDist == dist[nxtNode]) 
				minDist[nxtNode].push_back({ nxtDist, curNode });
		}
	}
	if (dist[d] == INF) dist[d] = -1;
	return dist[d];
}

void bfs() {
	queue<int> q;
	q.push(d);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (auto i : minDist[cur]) {
			int nxtNode = i.NODE;
			if (vis[cur][nxtNode]) continue;
			for (auto &j : a[nxtNode]) {
				if (j.NODE == cur) 
					j.DIST = -1;
			}
			vis[cur][nxtNode] = 1;
			q.push(nxtNode);
		}
	}
}

void solution() {
	while (input()) {
		dijkstra();
		bfs();
		cout << dijkstra() << '\n';
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	solution();
	return 0;
}
