#include<bits/stdc++.h>
using namespace std;

int dp[100001];

int main() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n, x, y;
	cin >> n;
	cin >> dp[1];
	for (int i = 2; i <= n; i++) {
		cin >> dp[i];
		dp[i] += dp[i - 1];
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		cout << dp[y] - dp[x - 1] << '\n';
	}
	return 0;
}
