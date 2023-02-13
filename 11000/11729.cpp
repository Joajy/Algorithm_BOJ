#include<iostream>
using namespace std;

void func(int a, int b, int c) {
	if (c == 1) { cout << a << ' ' << b << '\n'; return; }
	func(a, 6 - a - b, c - 1);
	cout << a << ' ' << b << '\n';
	func(6 - a - b, b, c - 1);
}

int main() {
	cin.tie();
	ios::sync_with_stdio();
	int x;
	cin >> x;
	cout << (1 << x) - 1 << '\n';
	func(1, 3, x);
}
