#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
#define p pair<int, int>

int n, m, src, dst;
vector<p> v[1001];//cost, dst
int dist[1001], before[1001];

void input() {
	cin >> n >> m;
	int a, b, c;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> c;
		v[a].push_back({ c,b });
	}
	cin >> src >> dst;
}

void dijkstra() {
	fill(dist, dist + n + 1, 2000000000);
	priority_queue<p> pq;
	pq.push({ 0, src });
	dist[src] = 0;
	while (!pq.empty()) {
		int curCost = -pq.top().first;
		int curNode = pq.top().second;
		pq.pop();
        if(curCost > dist[curNode]) continue;
		for (p nxt : v[curNode]) {
			int nxtCost = curCost + nxt.first;
			int nxtNode = nxt.second;
			if (dist[nxtNode] > nxtCost) {
				before[nxtNode] = curNode;
				dist[nxtNode] = nxtCost;
				pq.push({ -nxtCost, nxtNode });
			}
		}
	}
}

bool cmp(int a, int b) {
	return a < b;
}

void solution() {
	input();
	dijkstra();
	cout << dist[dst] << '\n';
	vector<int> answer;
	while (dst) {
		answer.push_back(dst);
		dst = before[dst];
	}
	cout << answer.size() << '\n';
	for (int i = answer.size() - 1; i >= 0; --i) {
		cout << answer[i] << ' ';
	}
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
