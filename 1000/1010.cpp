#include<iostream>
#include<cstring>
using namespace std;

int dp[30][30];

int C(int n, int r) {
	if (n == r || r == 0)
		return 1;
	if (dp[n][r] != -1)
		return dp[n][r];
	return dp[n][r] = C(n - 1, r) + C(n - 1, r - 1);
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	int t, a, b;
	cin >> t;
	memset(dp, -1, sizeof(dp));
	while (t--) {
		cin >> a >> b;
		cout << C(b, a) << '\n';
	}
	return 0;
}
