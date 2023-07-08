#include<iostream>
using namespace std;

int n, m, k;
int dp[301][301]{ 0 };

void input() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> dp[i][j];
			dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
		}
	}
	cin >> k;
}

void solution() {
	input();
	int a, b, c, d;
	for (int i = 0; i < k; ++i) {
		cin >> a >> b >> c >> d;
		int answer = dp[c][d] - dp[c][b - 1] - dp[a - 1][d] + dp[a - 1][b - 1];
		cout << answer << '\n';
	}
}

int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
