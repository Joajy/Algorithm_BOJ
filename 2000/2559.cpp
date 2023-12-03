#include <iostream>
#include <vector>
using namespace std;

int n, k;
int a[100001];
int prefix[100001];

void init() {
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		prefix[i] = a[i];
		if (i == 0) continue;
		prefix[i] += prefix[i - 1];
	}
}

void solution() {
	init();
	int ans = 0, answer = -1e9;
	for (int i = k; i <= n; ++i) {
		ans = prefix[i] - prefix[i - k];
		if (ans > answer) answer = ans;
	}
	cout << answer;
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
