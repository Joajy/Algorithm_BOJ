#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> v[501];
int indeg[501], period[501], result[501];

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		int a, b;
		cin >> a >> b;
		result[i] = period[i] = a;
		while (b != -1) {
			v[b].push_back(i);
			indeg[i]++;
			cin >> b;
		}
	}
	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (indeg[i] == 0) q.push(i);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int nxt : v[cur]) {
			if (--indeg[nxt] == 0)
				q.push(nxt);
			result[nxt] = max(result[nxt], result[cur] + period[nxt]);
		}
	}
	for (int i = 1; i <= n; i++)
		cout << result[i] << '\n';
	return 0;
}
