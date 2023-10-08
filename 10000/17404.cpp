#include<iostream>
using namespace std;

int n, answer = 1e9;
int cost[1001][3];

int min(int a, int b) {
	if (a < b) return a;
	return b;
}

void input() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> cost[i][j];
		}
	}
}

void findMin(int idx) {
	int dp[1001][3];
	int a = (idx + 1) % 3, b = (idx + 2) % 3;
	for (int i = 0; i < 3; ++i) {
		dp[1][i] = cost[1][i];
	}
	for (int i = 2; i <= n; ++i) {
		for (int j = 0; j < 3; ++j) {
			dp[i][j] = 1e9;
		}
	}
	dp[2][a] = dp[1][idx] + cost[2][a];
	dp[2][b] = dp[1][idx] + cost[2][b];
	for (int i = 3; i < n; ++i) {
		dp[i][a] = min(dp[i - 1][b], dp[i - 1][idx]) + cost[i][a];
		dp[i][b] = min(dp[i - 1][a], dp[i - 1][idx]) + cost[i][b];
		dp[i][idx] = min(dp[i - 1][a], dp[i - 1][b]) + cost[i][idx];
	}
	dp[n][a] = min(dp[n - 1][b], dp[n - 1][idx]) + cost[n][a];
	dp[n][b] = min(dp[n - 1][a], dp[n - 1][idx]) + cost[n][b];
	for (int i = 0; i < 3; ++i) {
		if (answer > dp[n][i]) answer = dp[n][i];
	}
}

void solution() {
 	input();
	for (int i = 0; i < 3; ++i) {
		findMin(i);
	}
	cout << answer;
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
 }
