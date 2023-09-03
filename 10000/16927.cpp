#include<iostream>
#include<algorithm>
using namespace std;

int n, m, r, rot;
int a[301][301];

void input() {
	cin >> n >> m >> r;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j];
		}
	}
	rot = min(n, m) >> 1;
}

void output() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cout << a[i][j] << ' ';
		}cout << '\n';
	}
}

void rotate(int cnt) {
	int tmp = a[cnt][cnt];
	for (int i = cnt; i <= m - cnt; ++i)  a[cnt][i] = a[cnt][i + 1];
	for (int i = cnt; i <= n - cnt; ++i)  a[i][m - cnt + 1] = a[i + 1][m - cnt + 1];
	for (int i = cnt; i <= m - cnt; ++i)  a[n - cnt + 1][m - i + 1] = a[n - cnt + 1][m - i];
	for (int i = cnt; i <= n - cnt; ++i)  a[n - i + 1][cnt] = a[n - i][cnt];
	a[cnt + 1][cnt] = tmp;
}

void solution() {
	input();
	for (int i = 0; i < rot; ++i) {
		int div = ((n + m) << 1) - 4 - (i << 3);
		div = r % div;
		for (int j = 0; j < div; ++j) {
			rotate(i + 1);
		}
	}
	output();
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
 	solution();
	return 0;
}
