#include<iostream>
#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std;

int ans[1001][1001]{ 0 };

int main() {
	fast;
	string x, y;
	cin >> x >> y;
	int m = x.length(), n = y.length();
	for (int i = 1; i < m; i++) ans[i][0] = 0;
	for (int j = 0; j < n; j++) ans[0][j] = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (x[i - 1] == y[j - 1]) 
				ans[i][j] = ans[i - 1][j - 1] + 1;
			else if (ans[i - 1][j] >= ans[i][j - 1]) 
				ans[i][j] = ans[i - 1][j];
			else 
				ans[i][j] = ans[i][j - 1];
		}
	}
	cout << ans[m][n];
	return 0;
}
