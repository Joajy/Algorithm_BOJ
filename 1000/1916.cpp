#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define MAX 1000
#define MAXB 100'000
int n, m, st, en;
vector<pair<int, int>> v[MAX + 1];
long long dist[MAX + 1];

void init() {
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ c,b });
	}
	cin >> st >> en;
    long long tmp = MAXB* MAX;
    for (int i = 1; i <= n; ++i) dist[i] = tmp;
}

void solution() {
	init();
	dist[st] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, st });
	while (!pq.empty()) {
		int curDist = -pq.top().first;
		int curNode = pq.top().second;
		pq.pop();
        if(dist[curNode] < curDist) continue;
		for (auto i : v[curNode]) {
			int nxtNode = i.second;
			int nxtDist = curDist + i.first;
			if (dist[nxtNode] > nxtDist) {
				dist[nxtNode] = nxtDist;
				pq.push({ -nxtDist, nxtNode });
			}
		}
	}
	cout << dist[en];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solution();
	return 0;
}
