#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> v[32002];
int indeg[32002];

int main() {
	cin.tie(0); cout.tie(0);
  ios_base::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	vector<int> ans;
	queue<int> q;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		indeg[b]++;
	}
	for (int i = 1; i <= n; i++)
		if (indeg[i] == 0)
			q.push(i);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		ans.push_back(cur);
		for (int nxt : v[cur]) {
			indeg[nxt]--;
			if (indeg[nxt] == 0)
				q.push(nxt);
		}
	}
	if (ans.size() != n) return 0;
	for (auto i : ans)
		cout << i << ' ';

	return 0;
}
