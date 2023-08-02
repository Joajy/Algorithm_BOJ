#include<iostream>
using namespace std;
#define ll long long

const int MAX = 1000001;
int n, m, k;
ll ar[MAX], seg[MAX << 1];

ll init(int st, int en, int node) {
	if (st == en) return seg[node] = ar[st];
	int mid = (st + en) >> 1;
	return seg[node] = init(st, mid, node << 1) + init(mid + 1, en, (node << 1) + 1);
}

ll update(int st, int en, int node, int idx, ll val) {
	if (idx < st || idx > en) return seg[node];
	if (st == en) return seg[node] = val;
	int mid = (st + en) >> 1;
	return seg[node] = update(st, mid, node << 1, idx, val) + update(mid + 1, en, (node << 1) + 1, idx, val);
}

ll sum(int st, int en, int left, int right, int node) {
	if (left > en || right < st) return 0;
	if (left <= st && en <= right) return seg[node];
	int mid = (st + en) >> 1;
	return sum(st, mid, left, right, node << 1) + sum(mid + 1, en, left, right, (node << 1) + 1);
}

void solution() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> ar[i];
	}
	init(1, n, 1);
	int a, b;
    ll c;
	for (int i = 0; i < m + k; ++i) {
		cin >> a >> b >> c;
		if (a == 1) {
			update(1, n, 1, b, c);
		}
		else {
			cout << sum(1, n, b, c, 1) << '\n';
		}
	}

}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
