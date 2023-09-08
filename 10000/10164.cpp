#include <iostream>
using namespace std;

int n, m, k;
int dp[16][16];

void input() {
	cin >> n >> m >> k;
}

void solution() {
	input();
	for (int i = 1; i <= 15; ++i) {
		dp[i][1] = dp[1][i] = 1;
	}
	if (k == 0) {
		for (int i = 2; i <= n; ++i) {
			for (int j = 2; j <= m; ++j) {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		cout << dp[n][m];
	}
	else {
		int r = k / m + 1, c = k % m;
		if (c == 0) {
			--r;
			c = m;
		}
		for (int i = 2; i <= r; ++i) {
			for (int j = 2; j <= c; ++j) {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		int tmp = dp[r][c];
		dp[r][c] = 1;
		for (int i = c + 1; i <= m; ++i) {
			dp[r][i] = 1;
		}
		for (int i = r + 1; i <= n; ++i) {
			dp[i][c] = 1;
		}
		for (int i = r + 1; i <= n; ++i) {
			for (int j = c + 1; j <= m; ++j) {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		cout << tmp * dp[n][m];
	}
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
