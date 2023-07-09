#include<iostream>
using namespace std;

int n, m;

void input() {
	cin >> n >> m;
}

int gcd(int a, int b) {
	if (a == 0) return b;
	return gcd(b % a, a);
}

void solution() {
	input();
	cout << m - gcd(n, m);
}

int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
