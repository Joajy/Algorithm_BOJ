#include<iostream>
#include<queue>
using namespace std;
#define p pair<int, int>
int f, s, g, u, d;
bool vis[1000001]{ 0 };

void input() {
	cin >> f >> s >> g >> u >> d;
}

void solution() {
	input();
	if (s == g) {
		cout << 0;
		return;
	}
	queue<p> q;
	q.push({ s, 0 });
	while (!q.empty()) {
		p cur = q.front(); q.pop();
		if (cur.first == g) {
			cout << cur.second;
			return;
		}
		if (cur.first + u <= f && !vis[cur.first + u]) {
			q.push({ cur.first + u, cur.second + 1});
			vis[cur.first + u] = 1;
		}
		if (cur.first - d >= 1 && !vis[cur.first - d]) {
			q.push({ cur.first - d , cur.second + 1});
			vis[cur.first - d] = 1;
		}
	}
	cout << "use the stairs";
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
