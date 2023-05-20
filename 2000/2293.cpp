#include<iostream>
using namespace std;

int dp[10001]{ 1 };
int coin[101]{ 0 };
int n, k;

void input() {
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> coin[i];
	}
}

void solution() {
	input();
	for (int i = 0; i < n; ++i) {
		if (coin[i] > 10000) continue;
		for (int j = coin[i]; j <= k; ++j) {
			dp[j] += dp[j - coin[i]];
		}
	}
	cout << dp[k];
}

int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
