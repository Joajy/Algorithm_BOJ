#include<iostream>
using namespace std;

int n, maxVal = -1e9, minVal = 1e9;
int num[11];
int op[4];

void input() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> num[i];
	}
	for (int i = 0; i < 4; ++i) {
		cin >> op[i];
	}
}

void rec(int val, int idx, int plus, int minus, int mul, int div) {
	++idx;
	if (idx == n) {
		if (maxVal < val) maxVal= val;
		if (minVal > val) minVal = val;
		return;
	}
	if (plus > 0) rec(val + num[idx], idx, plus - 1, minus, mul, div);
	if (minus > 0) rec(val - num[idx], idx, plus, minus - 1, mul, div);
	if (mul > 0) rec(val * num[idx], idx, plus, minus, mul - 1, div);
	if (div > 0) rec(val / num[idx], idx, plus, minus, mul, div - 1);
}

void solution() {
	input();
	rec(num[0], 0, op[0], op[1], op[2], op[3]);
	cout << maxVal << '\n' << minVal;
}

int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
