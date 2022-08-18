#include<iostream>
#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std;

int dp[302][3];
int s[302];

int main() {
	fast;
	int n, ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> s[i];
	dp[1][0] = s[1];
	dp[2][0] = s[2];
	dp[2][1] = s[1] + s[2];
	for (int i = 1; i < n; i++) {
		dp[i + 2][2] = dp[i][1] + s[i + 2];
		dp[i + 2][0] = max(dp[i][0] + s[i + 2], dp[i][1] + s[i + 2]);
		dp[i + 2][1] = dp[i + 1][0] + s[i + 2];
	}
	ans = max(dp[n][2], max(dp[n][0], dp[n][1]));
	cout << ans;

	return 0;
}