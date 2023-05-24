#include<iostream>
#include<cmath>
using namespace std;

#define MAX 201
int dp[MAX][MAX];	//row: n, col: k
int n, k;

void input() {
	cin >> n >> k;
}

void solution() {
	input();
	int maxVal = max(n, k);
	for (int i = 1; i <= maxVal; ++i) {
		dp[1][i] = i;
		dp[i][1] = 1;
	}
	for (int i = 2; i <= maxVal; ++i) {
		for (int j = 2; j <= maxVal; ++j) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			dp[i][j] %= 1'000'000'000;
		}
	}
	cout << dp[n][k];
}

int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
