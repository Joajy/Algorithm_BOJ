#include<iostream>
using namespace std;

int n, m;
int a[2002], dp[2002][2002];

void input() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	cin >> m;
}

void solve() {
	for (int i = 1; i <= n; ++i) {
		int s1 = i, e1 = i;
		int s2 = i - 1, e2 = i;
		bool odd = 1, even = 1;
		while (odd) {
			if (a[s1] == a[e1]) dp[s1--][e1++] = 1;
			else break;
			if (s1 < 0 || e1 > n) break;
		}
		while (even) {
			if (a[s2] == a[e2]) dp[s2--][e2++] = 1;
			else break;
			if (s2 < 0 || e2 > n) break;
		}
	}
	int s, e;
	for (int i = 0; i < m; ++i) {
		cin >> s >> e;
		cout << dp[s][e] << '\n';
	}
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	input();
	solve();
	return 0;
}
