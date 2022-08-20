#include<iostream>
#include<utility>
#include<algorithm>
#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std;

pair<int, int> a[100001];

int main() {
	fast;
	int t, n;
	cin >> t;
	while (t--) {
		int ans = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			a[i] = make_pair(x, y);
		}
		sort(a, a + n);
		pair<int, int> cur = a[0];
		for (int i = 0; i < n; i++) {
			if (cur.second < a[i].second) continue;
			else cur = a[i];
			ans++;
		}
		cout << ans << '\n';
	}
	return 0;
}
