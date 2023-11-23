#include <iostream>
#include <cmath>
using namespace std;

int n;
char a[540001];

void rec(int st, int en, bool okay) {
	if (st == en) return;
	for (int j = st;j<en; ++j) {
		a[j] = '-';
	}
	int d = (en - st + 1) / 3;
	for (int i = 0; i < 3; ++i) {
		if (i == 1) {
			for (int j = st + d; j < st + d * 2; ++j) {
				a[j] = ' ';
			}
			continue;
		}
		rec(st + d * i, st + d * (i + 1) - 1, !okay);
	}
}

void solution() {
	rec(0, pow(3, 12), 0);
	while (cin >> n) {
		for (int i = 0; i < pow(3,n); ++i) {
			cout << a[i];
		}cout << '\n';
	}
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
