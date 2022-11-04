#include<iostream>
#include<map>
#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define ll long long
using namespace std;

map < ll, ll> m;
ll n, p, q;

ll dp(ll n) {
	if (m.count(n))
		return m[n];
	return m[n] = dp(n / p) + dp(n / q);
}

int main() {
	fast;
	m[0] = 1;
	cin >> n >> p >> q;
	cout << dp(n);
	return 0;
}
