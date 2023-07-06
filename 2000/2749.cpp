#include<iostream>
using namespace std;
#define ll long long
#define DIV 1000000

ll n;
int dp[DIV*15]{ 0,1,1 };

void input() {
	cin >> n;
}

void fib(ll x) {
	if (x > 1) {
		for (ll i = 2; i <= x; ++i) {
			dp[i] = (dp[i - 1] + dp[i - 2]) % DIV;
		}
	}
	cout << dp[x];
}

void solution() {
	input();
	int tmp = 15 * DIV;
	n %= tmp;
	fib(n);
}

int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
