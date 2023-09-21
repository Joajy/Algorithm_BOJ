#include<iostream>
#include<algorithm>
using namespace std;

int n, m, finish;
int a[101], c[101];
int dp[101][10001];

void input() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
		finish += c[i];
	}
}

void solution() {
	input();
	dp[1][0] = 0;
	dp[1][c[1]] = a[1];
	for (int i = 2; i <= n; ++i) {
		for (int j = 0; j <= finish; ++j) {
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			dp[i][j + c[i]] = max(dp[i - 1][j] + a[i], dp[i - 1][j + c[i]]);
		}
	}

	for (int i = 0; i <= finish; ++i) {
		if (dp[n][i] >= m) {
			cout << i;
			return;
		}
	}
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
