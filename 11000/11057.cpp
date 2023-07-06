#include<iostream>
using namespace std;

int n, answer = 0;
int dp[1001][10];

void input() {
	cin >> n;
	for (int i = 0; i < 10; ++i) {
		dp[1][i] = 1;
	}
	for (int i = 1; i <= n; ++i) {
		dp[i][9] = 1;
	}
}

void solution() {
	input();
	for (int i = 2; i <= n; ++i) {
		for (int j = 8; j >= 0; --j) {
			dp[i][j] = dp[i - 1][j] + dp[i][j + 1];
			dp[i][j] %= 10007;
		}
	}
	for (int i = 0; i < 10; ++i) {
		answer += dp[n][i];
    answer %= 10007;
	}
	cout << answer;
}

int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
