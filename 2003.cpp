#include<iostream>
#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std;

int a[10001];

int main() {
	fast;
	int n, m, ans = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++) {
		int sum = a[i];
		for (int j = i + 1; j <= n; j++) {
			if (sum == m) {
				ans++;
				break;
			}
			if (sum > m) break;
			sum += a[j];
		}
	}
	cout << ans;
	return 0;
}