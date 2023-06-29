#include<iostream>
using namespace std;
#define MAX 1'000'000'000

int n, l;

void input() {
	cin >> n >> l;
}

void solution() {
	input();
	int a = 0, cnt = 0;
	for (int i = l; i <= 100; ++i) {
		int t = ((i * (i - 1)) >> 1);
		a = (n - t) / i;
		if (a >= 0 && (n - t) % i == 0) {
			for (int j = a; j < a + i; ++j) {
				cout << j << ' ';
			}
			return;
		}
	}
	cout << -1;
	return;
}

int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
