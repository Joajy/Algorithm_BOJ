#include<iostream>
using namespace std;

const int MAX = 100001;
int n, m, k;
int ar[MAX], seg[MAX << 2];

int min(int a, int b) {
	if (ar[a] == ar[b]) {
		if (a < b) return a;
		return b;
	}
	if (ar[a] < ar[b]) return a;
	return b;
}

int init(int st, int en, int node) {
	if (st == en) return seg[node] = st;
	int mid = (st + en) >> 1;
	return seg[node] = min(init(st, mid, node << 1), init(mid + 1, en, (node << 1) + 1));
}

int update(int st, int en, int node, int idx, int val) {
	if (idx < st || idx > en) return seg[node];
	if (st == en) return seg[node];
	int mid = (st + en) >> 1;
	return seg[node] = min(update(st, mid, node << 1, idx, val), update(mid + 1, en, (node << 1) + 1, idx, val));
}

void solution() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> ar[i];
	}
	init(1, n, 1);
	cin >> m;
	int a, b;
	for (int i = 0; i < m; ++i) {
		cin >> a;
		if (a == 1) {
			cin >> a >> b;
			ar[a] = b;
			update(1, n, 1, a, b);
		}
		else {
			cout << seg[1] << '\n';
		}
	}
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
