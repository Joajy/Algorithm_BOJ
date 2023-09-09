#include <iostream>
#include <vector>
using namespace std;
#define p pair<int, int>

int n, answer = 0;
vector<p> v[100001];
bool vis[100001]{ 0 };

void input() {
	cin >> n;
	int a, b, c;
	for (int i = 0; i < n - 1; ++i) {
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
}

void dfs(int i, int dist) {
	if (answer < dist) answer = dist;
	for (p nxt : v[i]) {
		if (vis[nxt.first]) continue;
		vis[nxt.first] = 1;
		dfs(nxt.first, dist + nxt.second);
		vis[nxt.first] = 0;
	}
}

void solution() {
	input();
	for (int i = (n >> 1) + 1; i <= n; ++i) {
		vis[i] = 1;
		dfs(i, 0);
		vis[i] = 0;
	}
	cout << answer;
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
