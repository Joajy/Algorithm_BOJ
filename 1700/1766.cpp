#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> v[32001];
int indeg[32001];

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n, m, a, b;
	cin >> n >> m;
	while (m--) {
		cin >> a >> b;
		v[a].push_back(b);
		indeg[b]++;
	}
	priority_queue<int, vector<int>, greater<int>> q;
	for (int i = 1; i <= n; i++)
		if (indeg[i] == 0) q.push(i);
	while (!q.empty()) {
		int cur = q.top(); q.pop();
		cout << cur << ' ';
		for (int nxt : v[cur])
			if (--indeg[nxt] == 0) q.push(nxt);
	}
	return 0;
}
