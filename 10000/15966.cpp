#include <iostream>
using namespace std;

int n;
int a[1'000'001];
int dp[1'000'001];

void init() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
}

void solution() {
	init();
	int answer = 1;
	dp[a[0]] = 1;
	for (int i = 1; i < n; ++i) {
		if (dp[a[i] - 1] >= 0) {
			dp[a[i]] = dp[a[i] - 1] + 1;
			if (answer < dp[a[i]]) answer = dp[a[i]];
		}
		else if (a[i - 1] == a[i]) {
			dp[a[i]] = dp[a[i] - 1];
		}
	}
	cout << answer;
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
