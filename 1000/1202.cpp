#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

const int MAX = 300'001;
pair<int, int> jew[MAX];
int bag[MAX];
long long ans;
priority_queue<int> pq;

void input(int& n, int& k) {
	ans = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> jew[i].first >> jew[i].second;
	for (int i = 0; i < k; i++) cin >> bag[i];
	sort(jew, jew + n);
	sort(bag, bag + k);
}

void solve(int n, int k, int idx) {
	for (int i = 0; i < k; i++) {
		while (idx < n && jew[idx].first <= bag[i])
			pq.push(jew[idx++].second);
		if (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, k;
	input(n, k);
	solve(n, k, 0);
	cout << ans;
	return 0;
}
