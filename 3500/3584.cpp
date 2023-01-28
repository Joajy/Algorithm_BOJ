#include<iostream>
#include<cstring>
using namespace std;
#define MAX 10001

int parent[MAX];
bool vis[MAX];

void Find(int x) {
	if (x == 0) return;
	vis[x] = 1;
	Find(parent[x]);
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	int t, n, x, y;
	cin >> t;
	for (int z = 1; z <= t; z++) {
		cin >> n;
		memset(vis, 0, sizeof(int) * n);
		memset(parent, 0, sizeof(int) * n);
		for (int i = 0; i < n - 1; i++) {
			cin >> x >> y;
			parent[y] = x;
		}
		cin >> x >> y;
		Find(x);
		while (y != 0) {
			if (vis[y]) break;
			y = parent[y];
		}
		cout << y << '\n';
	}
	return 0;
}
