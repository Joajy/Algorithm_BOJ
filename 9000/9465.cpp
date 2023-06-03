#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 100000
int n;
int dp[2][MAX]{ 0 };
int area[2][MAX];

void input() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> area[0][i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> area[1][i];
	}
}

void solution() {
	input();
	for (int i = 1; i <= n; ++i) {
		dp[0][i] = max(dp[1][i - 1] + area[1][i - 1], dp[0][i - 1]);
		dp[1][i] = max(dp[0][i - 1] + area[0][i - 1], dp[1][i - 1]);
	}
	cout << max(dp[0][n], dp[1][n]) << '\n';
}

int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		solution();
	}
	return 0;
}
