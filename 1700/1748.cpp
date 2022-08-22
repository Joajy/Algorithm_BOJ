#include<iostream>
#include<cmath>
#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std;

int a[10];

int main() {
	fast;
	int n, z, ans = 0, cnt = 0;
	cin >> z;
	n = z;
	if (n < 10) {
		cout << n;
		return 0;
	}
	while (n >= 1) {
		if (n / 10 >= 1)
			a[cnt++] = 9 * pow(10, cnt);
		else {
			int x = pow(10, cnt + 1);
			a[cnt++] = z % x - pow(10, cnt) + 1;
		}
		n /= 10;
	}
	for (int i = 0; i < cnt; i++)
		ans += a[i] * (i + 1);

	cout << ans;
	return 0;
}
