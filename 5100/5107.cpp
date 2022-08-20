#include<iostream>
#include<utility>
#define X first
#define Y second
using namespace std;
int main() {
	int n, cnt = 0;
	while (cin >> n) {
		if (n == 0) return 0;
		int ans = 0;
		//X.X: from, X.Y: to, Y: visited
		pair<pair<string, string>, bool> x[21];
		for (int i = 0; i < n; i++)
			cin >> x[i].X.X >> x[i].X.Y;
		for (int k = 0; k < n; k++) {
			pair<pair<string, string>, bool> cur = x[k];
			pair<pair<string, string>, bool> curr = x[k];
			x[k].Y = true;
			int cnt = 0;
			for (int i = 0; i < n; i++) {
				//already visited
				if (x[i].Y == true) continue;
				for (int j = 0; j < n; j++) {
					if (k == j) continue;
					if (curr.X.Y == x[j].X.X && x[j].Y == false) {
						curr = x[j];
						x[j].Y = true;
						cnt++;
						break;
					}
				}
			}
			if (curr.X.X == cur.X.Y && curr.X.Y == cur.X.X || cnt > 0) ans++;
		}
		cout << ++cnt << ' ' << ans << '\n';
	}
}
