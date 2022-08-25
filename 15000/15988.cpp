#include<iostream>
#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std;
using ull = unsigned long long;

ull dp[1000002]{ 0,1,2,4,7 };

int main() {
	int T, n;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		for (int i = 4; i <= n; i++)
			dp[i] = ((dp[i - 1] + dp[i - 2]) % 1000000009 + dp[i - 3]) % 1000000009;
		cout << dp[n] << endl;
	}
	return 0;
}