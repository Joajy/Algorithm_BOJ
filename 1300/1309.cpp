#include<iostream>
#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int dp[100001]{ 0, 3,7 };

int main() {
	fast;
	int n;
	cin >> n;
	for (int i = 3;i <= n;i++) {
		dp[i] = (2 * dp[i - 1] + dp[i - 2]) % 9901;
	}
	cout << dp[n];
	return 0;
}
