#include<iostream>
using namespace std;

int n, b, c;
int a[1000001];

void input() {
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	cin >> b >> c;
}

void solution() {
	input();
	long long answer = n;
	for (int i = 1; i <= n; ++i) {
		a[i] -= b;
		if (a[i] <= 0) continue;
		answer += a[i] / c;
		if (a[i] % c > 0) ++answer;
	}
	cout << answer;
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
