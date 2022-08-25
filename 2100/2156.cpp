#include<iostream>
#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std;
using ull = unsigned long long;

int dp[10002]{ 0 };
int a[10002];

int main() {
	fast;
	int n;
	cin >> n;
	for (int i = 1; i<= n; i++)		cin >> a[i];
	dp[1] = a[1];
	dp[2] = a[1] + a[2];
	int ans = max(a[1], a[1] + a[2]);
	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 3] + a[i - 1] + a[i], max(dp[i - 2] + a[i], dp[i - 1]));
		ans = max(dp[i], ans);
	}
	cout << ans;
	return 0;
}
