#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n, m;
int indeg[32001];
vector<int> v[32001];

void input() {
	cin >> n >> m;
	int a, b;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		v[a].push_back(b);
		++indeg[b];
	}
}

void solution() {
	input();
	queue<int> q;
	for (int i = 1; i <= n; ++i) {
		if (indeg[i] == 0) q.push(i);
	}
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		cout << cur << ' ';
		for (int nxt : v[cur]) {
			if (--indeg[nxt] == 0) {
				q.push(nxt);
			}
		}
	}
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
