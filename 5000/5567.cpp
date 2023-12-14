#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
#define p pair<int, int>

int n, m;
vector<int> v[501];
set<int> s;

void init() {
	cin >> n >> m;
	int a, b;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
}

void solution() {
	init();
	queue<p> q;
	q.push(p(1, 0));
	while (!q.empty()) {
		p cur = q.front(); q.pop();
		if (cur.second == 3) continue;
		s.insert(cur.first);
		for (int nxt : v[cur.first]) {
			q.push(p(nxt, cur.second + 1));
		}
	}
	cout << s.size() - 1;
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
