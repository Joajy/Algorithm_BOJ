#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int k, v, e, st;
int vis[20001];
vector<int> edge[20001];
bool err;

void left(int);
void right(int);

void left(int cur) {
	for (int i : edge[cur]){
		if (vis[i]) {
			if (vis[i] == 2) {
				err = 1;
				return;
			}
			continue;
		}
		vis[i] = 1;
		right(i);
	}
}

void right(int cur) {
	for (int i : edge[cur]) {
		if (vis[i]) {
			if (vis[i] == 1) {
				err = 1;
				return;
			}
			continue;
		}
		vis[i] = 2;
		left(i);
	}
}

void input() {
	err = 0;
	cin >> v >> e;
	for (int i = 1; i <= v; ++i) {
		edge[i].clear();
		vis[i] = 0;
	}
	int a, b;
	for (int i = 0; i < e; ++i) {
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
		st = a;
	}
}

void solve() {
	cin >> k;
	while (k--) {
		input();
		for (int i = 1; i <= v; ++i) {
			if (vis[i]) continue;
			left(i);
		}
		if (!err)cout << "YES\n";
		else cout << "NO\n";
	}

}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solve();
	return 0;
}
