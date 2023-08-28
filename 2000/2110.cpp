#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, c;
vector<int> router;

void input() {
	cin >> n >> c;
	int cur;
	for (int i = 1; i <= n; ++i) {
		cin >> cur;
		router.push_back(cur);
	}
}

void solution() {
	input();
	sort(router.begin(), router.end());
	int st = 1, en = router[n - 1] - router[0], mid, answer = 0;
	while (st <= en) {
		mid = (st + en) >> 1;
		int cnt = 1, prev = router[0];
		for (int i = 1; i < n; ++i) {
			if (router[i] - prev < mid) continue;
			++cnt;
			prev = router[i];
		}
		if (cnt >= c) {
			answer = max(answer, mid);
			st = mid + 1;
		}
		else {
			en = mid - 1;
		}
	}
	cout << answer;
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
} 
