#include<iostream>
using namespace std;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, ans = 1;
	cin >> n >> m;
	string t[51];

	for (int i = 0; i < n; i++)
		cin >> t[i];
	for (int i = 0; i < n * m; i++) {
		int cnt = 0, sq = 1, x = i / m, y = i % m;
		char c = t[x][y];
		while (1) {
			if (x + cnt >= n || y + cnt >= m) break;
			if (t[x + cnt][y] == c && t[x][y + cnt] == c && t[x + cnt][y + cnt] == c)
				sq = (cnt + 1) * (cnt + 1);
			cnt++;
		}
		if (ans < sq) ans = sq;
	}
	cout << ans;
	return 0;
}