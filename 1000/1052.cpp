#include <iostream>
using namespace std;

int n, k;

int cnt(int num) {
	int cnt1 = 0;
	while (num > 0) {
		if (num % 2) {
			++cnt1;
		}
		num >>= 1;
	}
	return cnt1;
}

void input() {
	cin >> n >> k;
}

void solution() {
	input();
	if (k >= n) {
		cout << 0;
		return;
	}
	int plus = 0;
	while (1) {
		int cur = plus + n;
		int count = cnt(cur);
		if (count <= k) {
			cout << plus;
			return;
		}
		++plus;
	}
	cout << -1;
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
