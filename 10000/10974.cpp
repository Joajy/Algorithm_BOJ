#include<iostream>
#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

bool vis[9];
int ans[9];
int n;

void rec(int x) {
	if (x == n) {
		for (int i = 0; i < x; i++)
				cout << ans[i] + 1 << ' ';
		cout << '\n';
	}
	for (int i = 0; i < n; i++) {
		if (vis[i]) continue;
		ans[x] = i;
		vis[i] = 1;
		rec(x + 1);
		vis[i] = false;
	}
}

int main() {
	fast;
	cin >> n;
	rec(0);
	return 0;
}
