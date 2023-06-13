#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long

int n, k;
int line[10001];

void input() {
	cin >> k >> n;
	for (int i = 0; i < k; ++i) cin >> line[i];
}

void solution() {
	input();
	sort(line, line + k);
	ll low = 1, high = line[k - 1];
	int answer = 0;
	while (low <= high) {
		ll mid = (low + high) >> 1;
		int cnt = 0;
		for (int i = 0; i < k; ++i) {
			cnt += line[i] / mid;
		}
		if (cnt >= n) {
			if (mid > answer) answer = mid;
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	cout << answer;
}

int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
