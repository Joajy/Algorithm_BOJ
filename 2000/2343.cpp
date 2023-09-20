#include <iostream>
using namespace std;

int n, m, low = 0, high = 0, answer = 0;
int lecture[100001];

void input() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> lecture[i];
        if(low < lecture[i]) low = lecture[i];
        high += lecture[i];
	}
}

int minSize(int x) {
	int cnt = 0, sum = 0;
	for (int i = 1; i <= n; ++i) {
		if (sum + lecture[i] > x) {
			sum = 0;
			++cnt;
		}
		sum += lecture[i];
	}
	if (sum != 0) return ++cnt;
	return cnt;
}

void binarySearch() {
	int st = low, en = high;
	while (st <= en) {
		int mid = (st + en) >> 1;
		int cnt = minSize(mid);
		if (cnt > m) {
			st = mid + 1;
		}
		else {
			answer = mid;
			en = mid - 1;
		}
	}
}

void solution() {
	input();
	binarySearch();
	cout << answer;
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
