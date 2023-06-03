#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 1000
int n;
int card[MAX + 1], dp[MAX + 1];

void input() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> card[i];
	}
}

void solution() {
	input();
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			dp[i] = max(dp[i - j] + card[j], dp[i]);
		}
	}
	cout << dp[n];
}

int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
