#include<iostream>
#include<stack>
#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std;

int a[501][501];
int dp[501][501]{ 0 };

int main() {
	fast;
	int n, Max = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
			cin >> a[i][j];
	dp[0][0] = a[0][0];
	dp[1][0] = a[0][0] + a[1][0];
	dp[1][1] = a[0][0] + a[1][1];
	for (int i = 0; i < n - 1; i++) {
		dp[i + 1][0] = max(dp[i + 1][0], dp[i][0] + a[i + 1][0]);
		for (int j = 0; j <= i; j++) {
			dp[i + 1][j + 1] = max(max(dp[i + 1][j + 1], dp[i][j + 1] + a[i + 1][j + 1]), dp[i][j] + a[i + 1][j + 1]);
		}
	}
	for (int i = 0; i < n; i++) {
		Max = max(Max, dp[n - 1][i]);
	}
	cout << Max;
	return 0;
}
