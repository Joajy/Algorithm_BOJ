#include<iostream>
#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std;

int a[4000001], x[2000001];

int main() {
	fast;
	int n, ans = 0, cnt = 0;
	cin >> n;
	//Sieve of Eratosthenes
	for (int i = 2; i <= n; i++)
		a[i] = i;
	for (int i = 2; i <= n; i++) {
		if (a[i] == 0) continue;
		else
			x[cnt++] = a[i];
		for (int j = i * 2; j <= n; j += i)
			a[j] = 0;
	}
	//Two Pointer
	int st = 0, en = 0, sum = 0;
	for (int st = 0; st < cnt; st++) {
		while (en < cnt && sum < n)
			sum += x[en++];
		if (sum == n)
			ans++;
		sum -= x[st];
	}
	cout << ans;
	return 0;
}
