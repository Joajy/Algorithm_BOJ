#include<iostream>
using namespace std;

int n;
int a[1500001][2];
int dp[1500001];

void input() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i][0] >> a[i][1];
	}
}

void solve() {
	input();
	int answer = 0;
	for (int i = 1; i <= n; ++i) {
		if (answer < dp[i]) answer = dp[i];
		int day = i + a[i][0];
		dp[day] = max(dp[day], answer + a[i][1]);
		if (dp[i] > answer) answer = dp[i];
	}
	if (dp[n + 1] > answer) answer = dp[n + 1];
	cout << answer;
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solve();
	return 0;
}
