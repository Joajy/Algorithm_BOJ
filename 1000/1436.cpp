#include <iostream>
#include <string>
using namespace std;

int n, number;

void init() {
	cin >> n;
	number = 666;
}

void solution() {
	init();
	while (n) {
		string s = to_string(number);
		if (s.find("666") != string::npos) {
			n--;
		}
		if (n == 0) break;
		++number;
	}
	cout << number;
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
