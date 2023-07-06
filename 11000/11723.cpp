#include<iostream>
using namespace std;

int n, answer = 0, x = 1;

void input() {
	cin >> n;
}

void add(int num) {
	answer |= (x << --num);
}

void remove(int num) {
	if(answer & (x << (num - 1)))
		answer ^= (x << --num);
}

int check(int num) {
	if (answer & (x << --num)) return 1;
	return 0;
}

void toggle(int num) {
	answer ^= (x << --num);
}

void all() {
	answer = 0b11111'11111'11111'11111;
}

void solution() {
	input();
	string cmd;
	int num;
	for (int i = 0; i < n; ++i) {
		cin >> cmd;
		if (!(cmd == "all" || cmd == "empty")) cin >> num;
		if (cmd == "add") add(num);
		else if (cmd == "remove") remove(num);
		else if (cmd == "check") cout << check(num) << '\n';
		else if (cmd == "toggle") toggle(num);
		else if (cmd == "all") all();
		else answer = 0;
	}
}

int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
