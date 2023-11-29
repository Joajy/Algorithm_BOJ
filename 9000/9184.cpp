#include <iostream>
using namespace std;

int a, b, c;
int dp[21][21][21]{ 0 };

int w(int x, int y, int z) {
	if (x <= 0 || y <= 0 || z <= 0) return 1;
	if (x > 20 || y > 20 || z > 20) return w(20, 20, 20);
	if (dp[x][y][z] > 0) return dp[x][y][z];
	if (x < y && y < z) {
		return dp[x][y][z]
			= w(x, y, z - 1) + w(x, y - 1, z - 1) - w(x, y - 1, z);
	}
	return dp[x][y][z] = w(x - 1, y, z) + w(x - 1, y - 1, z)
		+ w(x - 1, y, z - 1) - w(x - 1, y - 1, z - 1);
}

void solution() {
	while (1) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) break;
		cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << '\n';
	}
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
