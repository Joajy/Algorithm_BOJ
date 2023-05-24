#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define MAX 1001
#define INF 2147483647
#define p pair<int, int>
int n, m, x;
vector<p> path[MAX];	//dst, cost
int dist1[MAX], dist2[MAX];

void input() {
	cin >> n >> m >> x;
	int src, dst, cost;
	for (int i = 0; i < m; ++i) {
		cin >> src >> dst >> cost;
		path[src].push_back(make_pair(dst, cost));
	}
}

void dijkstra(int cur) {
	for (int i = 1; i <= n; ++i) {
		dist1[i] = INF;
	}
	priority_queue<p> pq;
	pq.push(make_pair(0, cur));
	dist1[cur] = 0;
	while (!pq.empty()) {
		int curDist = -pq.top().first;
		int curNode = pq.top().second;
		pq.pop();
		if (curDist > dist1[curNode]) continue;
		for (p i : path[curNode]) {
			int nxtDist = i.second + curDist;
			int nxtNode = i.first;
			if (nxtDist < dist1[nxtNode]) {
				dist1[nxtNode] = nxtDist;
				pq.push(make_pair(-nxtDist, nxtNode));
			}
		}
	}

}

void solution() {
	int answer = 0;
	input();
	for (int i = 1; i <= n; ++i) {
		dijkstra(i);
		dist2[i] = dist1[x];
	}
	dijkstra(x);
	for (int i = 1; i <= n; ++i) {
		int val = dist1[i] + dist2[i];
		if (answer < val) answer = val;
	}
	cout << answer;
}

int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
