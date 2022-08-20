#include<iostream>
#include<algorithm>
#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std;

int a[100001];

int main() {
	fast;
	int n, m, ans = 2000000000;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	for (int st = 0; st < n - 1; st++) {
		int en = st + 1;
		while (a[en] - a[st] < m && en < n)
			en++;
		if (a[en] - a[st] < m) continue;
		ans = min(a[en] - a[st], ans);
	}
	cout << ans;
}