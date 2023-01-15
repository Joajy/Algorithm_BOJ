#include<iostream>
using namespace std;

int lcs[101][101][101];

int main() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);
	string a, b, c;
	cin >> a >> b >> c;
	int x = a.length(), y = b.length(), z = c.length();
	for (int i = 1; i <= x; i++) {
		for (int j = 1; j <= y; j++) {
			for (int k = 1; k <= z; k++) {
				if (a[i - 1] == b[j - 1] && a[i - 1] == c[k - 1])
					lcs[i][j][k] = lcs[i - 1][j - 1][k - 1] + 1;
				else
					lcs[i][j][k] = max(lcs[i][j][k - 1], max(lcs[i][j - 1][k], lcs[i - 1][j][k]));
			}
		}
	}
	cout << lcs[x][y][z];
	return 0;
}
