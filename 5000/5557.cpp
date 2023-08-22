#include<iostream>
using namespace std;
#define ll long long

int n, answer;
int a[101];
ll dp[101][21];

void input() {
	cin >> n;
	for (int i = 1; i < n; ++i) cin >> a[i];
	cin >> answer;
}

void solution() {
	input();
	dp[1][a[1]] = 1;
	for (int i = 2; i < n; ++i) {
		for (int j = 0; j <= 20; ++j) {
			if (j + a[i] <= 20) {
				dp[i][j] += dp[i - 1][j + a[i]];
			}
			if (j - a[i] >= 0) {
				dp[i][j] += dp[i - 1][j - a[i]];
			}
		}
	}
	cout << dp[n - 1][answer];
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
