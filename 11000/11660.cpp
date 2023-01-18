#include<iostream>
using namespace std;

int a[1025][1025];
int row[1025];

int main() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n, m, x1, x2, y1, y2;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			a[i][j] += a[i][j - 1];
			a[i][j - 1] += a[i - 1][j - 1];
		}
	}
	for (int i = 2; i <= n; i++)
		a[i][n] += a[i - 1][n];
	while (m--) {
		cin >> x1 >> y1 >> x2 >> y2;
		cout << a[x2][y2] - a[x1 - 1][y2] - a[x2][y1 - 1] + a[x1 - 1][y1 - 1] << '\n';
	}
	return 0;
}
