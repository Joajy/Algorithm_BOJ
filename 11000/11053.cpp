#include<iostream>
#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std;

int a[1002]{ 0 }, dp[1002];

int main() {
	fast;
	int n, Max = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		dp[i] = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] < a[j]) {
				dp[j] = max(dp[i] + 1, dp[j]);
			}
		}
		Max = max(dp[i], Max);
	}
	cout << Max;
	return 0;
}
