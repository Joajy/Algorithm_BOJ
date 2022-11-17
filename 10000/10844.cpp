#include<iostream>
#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std;

int dp[101][10];

int main() {
	fast;
	int n;
	long answer = 0;
	cin >> n;
	for (int i = 1;i < 10;i++) dp[1][i] = 1;
	for (int i = 2;i <= n;i++) {
		dp[i][0] = dp[i - 1][1];
		for (int j = 1;j < 9;j++)
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
		dp[i][9] = dp[i - 1][8];
	}
	for (int j = 0;j < 10;j++) {
		answer += dp[n][j];
		answer %= 1000000000;
	}
	cout << answer;
	return 0;
}
