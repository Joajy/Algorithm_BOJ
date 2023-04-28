#include<iostream>
#include<vector>
#define MAX 100'001
using namespace std;

int dp[MAX];
bool vis[MAX];
vector<int> tree[MAX];

void init(int n) {
	for (register int i = 1; i <= n; ++i) 
		dp[i] = 1;
}

int dfs(int node) {
	vis[node] = true;
	for (int child : tree[node]) {
		if (vis[child]) continue;
		dp[node] += dfs(child);
	}
	return dp[node];
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n, r, q, u, v;
	cin >> n >> r >> q;
	init(n);
	for (register int i = 0; i < n - 1; ++i) {
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	dfs(r);
	for (register int i = 0; i < q; i++) {
		cin >> u;
		cout << dp[u] << '\n';
	}
	return 0;
}
