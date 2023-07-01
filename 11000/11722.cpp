#include<iostream>
using namespace std;

int n, answer = 1;
int a[1001], dp[1001];

void input() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		dp[i] = 1;
	}
}

void solution() {
	input();
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (a[j] > a[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		if (dp[i] > answer) answer = dp[i];
	}
	cout << answer;
}

int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
