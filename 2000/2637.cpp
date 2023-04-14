#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 101

vector<pair<int, int>> v[MAX];
int indeg[MAX], cnt[MAX];
bool notBase[MAX]{ 0 };
int n, m, x, y, k;

void input() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> k;
		v[x].push_back({ y,k });
		notBase[x] = 1;
		indeg[y]++;
	}
}

void solution() {
	input();
	queue<int> q;
	cnt[n] = 1;
	q.push(n);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (auto i : v[cur]) {
			int nxt = i.first;
			cnt[nxt] += cnt[cur] * i.second;
			if (--indeg[nxt] == 0) q.push(nxt);
		}
	}
	for (int i = 1; i < n; i++) {
		if (notBase[i]) continue;
		cout << i << ' ' << cnt[i] << '\n';
	}
}

int main() {
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(0);
	solution();
	return 0;
}
