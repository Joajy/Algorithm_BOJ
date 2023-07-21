#include<iostream>
#include<queue>
using namespace std;

struct p {
	int x, y;
};

int n, t;
p home, dst;
p con[101];

void input() {
	cin >> n;
	cin >> home.x >> home.y;
	for (int i = 0; i < n; ++i) {
		cin >> con[i].x >> con[i].y;
	}
	cin >> dst.x >> dst.y;
}

int abs(int a) {
	if (a >= 0) return a;
	else return -a;
}

bool bfs(p a) {
	bool vis[101]{ 0 };
	queue<p> q;
	q.push(a);
	while (!q.empty()) {
		p cur = q.front(); q.pop();
		int dist = abs(cur.x - dst.x) + abs(cur.y - dst.y);
		if (dist <= 1000) return true;
		for (int i = 0; i < n; ++i) {
			dist = abs(con[i].x - cur.x) + abs(con[i].y - cur.y);
			if (vis[i] || dist > 1000) continue;
			vis[i] = 1;
			q.push({ con[i].x, con[i].y });
		}
	}
	return false;
}

void solution() {
	cin >> t;
	for (int i = 0; i < t; ++i) {
		input();
		if (bfs(home)) {
			cout << "happy\n";
		}
		else {
			cout << "sad\n";
		}
	}
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
