#include <iostream>
#include <queue>
using namespace std;
#define p pair<int, int>
#define INF 2147483647
int n, k;
int a[100'001];

void input() {
	cin >> n >> k;
	for (int i = 0; i <= 100000; i++) a[i] = INF;
	a[n] = 0;
}

void dijkstra() {
	priority_queue<p> pq;	//dist, node
	pq.push({ 0, n });
	while (!pq.empty()) {
		int curDist = -pq.top().first;
		int curNode = pq.top().second;
		pq.pop();
		//3 move style
		if (curNode > 0 && a[curNode - 1] > curDist + 1) {
			a[curNode - 1] = curDist + 1;
			if (curNode == k) continue;
			pq.push({ -(curDist + 1), curNode - 1 });
		}
		if (curNode < 100000 && a[curNode + 1] > curDist + 1) {
			a[curNode + 1] = curDist + 1;
			if (curNode == k) continue;
			pq.push({ -(curDist + 1), curNode + 1 });
		}
		if (curNode * 2 <= 100000 && a[curNode*2] > curDist) {
			a[curNode << 1] = a[curNode];
			if (curNode == (curNode << 1)) continue;
			if ((curNode << 1) == k || (curNode << 1) > k * 2) continue;
			pq.push({ -curDist, curNode << 1 });
		}
	}
	cout << a[k];
}

void solution() {
	input();
	dijkstra();
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	solution();
	return 0;
}
