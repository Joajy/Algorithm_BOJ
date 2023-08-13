#include<iostream>
using namespace std;
#define ll long long

int n;
int a[101][101];
ll dp[101][101];

void input() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
		}
	}
}

void solution() {
	input();
	dp[1][1] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			int move = a[i][j];
			if (move == 0) continue;
			if (i + move <= n) {
				dp[i + move][j] += dp[i][j];
			}
			if (j + move <= n) {
				dp[i][j + move] += dp[i][j];
			}
		}
	}
	cout << dp[n][n];
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
