#include<iostream>
#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std;

bool vis[14];
int back[14], ans[14];
int n;

void track(int idx, int st) {
	if (idx == 6) {
		for (int i = 0;i < 6;i++)
			cout << ans[back[i]] << ' ';
		cout << '\n';
	}
	for (int i = st;i <= n;i++) {
		if (vis[i]) continue;
		back[idx] = i;
		vis[i] = 1;
		track(idx + 1, i + 1);
		vis[i] = 0;
	}
}

int main() {
	fast;
	while (cin >> n) {
		if (n == 0) break;
		fill(vis, vis + n, 0);
		for (int i = 1;i <= n;i++) cin >> ans[i];
		track(0, 1);
		cout << '\n';
	}
	return 0;
}
