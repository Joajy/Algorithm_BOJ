#include <iostream>
using namespace std;
#define MAX 100001

int n, answer =-1e9;
int input[8];
int number[8];
bool vis[8]{ 0 };

int abs(int a, int b) {
	if (a < b) return b - a;
	return a - b;
}

int calculate() {
	int sum = 0;
	for (int i = 0; i < n - 1; ++i) {
		sum += abs(number[i] - number[i + 1]);
	}
	return sum;
}

void bt(int cur) {
	if (cur == n) {
		int sum = calculate();
		if (sum > answer) answer = sum;
		return;
	}
	int store;
	for (int i = 0; i < n; ++i) {
		if (vis[i]) continue;
		vis[i] = 1;
		store = number[cur];
		number[cur] = input[i];
		bt(cur + 1);
		vis[i] = 0;
		number[cur] = store;
	}
}

void init() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> input[i];
	}
}

void solution() {
	init();
	bt(0);
	cout << answer;
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
