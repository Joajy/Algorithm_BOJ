#include<iostream>
#include<map>
using namespace std;
#define ll long long

int t, n, m;
int a[1001], b[1001];
map<ll, int> x;

void input() {
	cin >> t >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	cin >> m;
	for (int i = 1; i <= m; ++i) {
		cin >> b[i];
	}
}

void solution() {
	input();
	ll answer = 0;
	for (int i = 1; i <= n; ++i) {
		ll sum = 0;
		for (int j = i; j <= n; ++j) {
			sum += a[j];
			++x[sum];
		}
	}
	for (int i = 1; i <= m; ++i) {
		ll sum = 0;
		for (int j = i; j <= m; ++j) {
			sum += b[j];
			answer += x[t - sum];
		}
	}
	cout << answer;
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
 	solution();
	return 0;
}
