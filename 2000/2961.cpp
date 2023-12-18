#include <iostream>
#include <queue>
using namespace std;
#define MAX 11

int n, answer = 1e9;
int a[MAX][2];

int abs(int x, int y) {
	if (x > y) return x - y;
	return y - x;
}

void init() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i][0] >> a[i][1];
	}
}

void bt(int cur, int s, int b) {
	int sum = abs(s, b);
	if (sum < answer) {
		answer = sum;
	}
	if (cur == n) return;
	for (int i = cur + 1; i < n; ++i) {
		bt(i, s * a[i][0], b + a[i][1]);
	}
}

void solution() {
	init();
	for (int i = 0; i < n; ++i) {
		bt(i, a[i][0], a[i][1]);
	}
	cout << answer;
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
