#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int indeg[1001];
int sem[1001];
vector<int> v[1001];

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n, m, a, b;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		indeg[b]++;
	}
	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (indeg[i] == 0) q.push(i);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int nxt : v[cur]) {
			sem[nxt] = sem[cur] + 1;
			if (--indeg[nxt] == 0)
				q.push(nxt);
		}
	}
	for (int i = 1; i <= n; i++)
		cout << sem[i] + 1 << ' ';
	return 0;
}
