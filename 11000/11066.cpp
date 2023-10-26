#include<iostream>
using namespace std;

#define MAX 501

int t, k;
int dp[MAX][MAX], page[MAX], sum[MAX];

void input() {
	cin >> k;
	for (int i = 1; i <= k; ++i) {
		cin >> page[i];
		sum[i] = sum[i - 1] + page[i];
	}
}

void solve() {
	cin >> t;
	while(t--) {
		input();
		for (int i = 1; i <= k; i++) {
			for (int j = 1; i + j <= k; j++) {
				dp[j][i + j] = 1e9;
				for (int k = j; k < i + j; k++) {
					dp[j][i + j] = min(dp[j][i + j],
										dp[j][k] + dp[k + 1][i + j] + sum[i + j] - sum[j - 1]);
				}
			}
		}
		cout << dp[1][k] << '\n';
	}
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solve();
	return 0;
}
