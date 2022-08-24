#include<iostream>
#include<algorithm>
#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std;

int dp[100001], a[100001];
int main() {
	fast;
	int n, ans;
	cin >> n;
	fill(dp, dp + n, -1000000000);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	dp[0] = a[0];
	ans = a[0];
	for (int i = 1; i < n; i++) {
		dp[i] = max(a[i], max(dp[i], dp[i - 1] + a[i]));
		ans = max(ans, dp[i]);
	}
	cout << ans;
	return 0;
}