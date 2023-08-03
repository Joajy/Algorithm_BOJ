#include<iostream>
using namespace std;

const int MAX = 1000001;
int ar[MAX], seg[MAX << 2];

void update(int st, int en, int node, int idx, int val) {
	if (idx < st || idx > en) return;
	seg[node] += val;
	if (st == en) return;
	int mid = (st + en) >> 1;
	update(st, mid, node << 1, idx, val);
	update(mid + 1, en, (node << 1) + 1, idx, val);
}

//idx: n번째 사탕
int query(int st, int en, int node, int k) {
	if (st == en) return st;
	int mid = (st + en) >> 1;
	if (seg[node << 1] >= k) return query(st, mid, node << 1, k);
	return query(mid + 1, en, (node << 1) + 1, k - seg[node << 1]);
}

void solution() {
	int n, a, b;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		if (a == 1) {
			cin >> a;
			int tmp = query(1, MAX - 1, 1, a);
			cout << tmp << '\n';
			update(1, MAX - 1, 1, tmp, -1);
		}
		else {
			cin >> a >> b;
			update(1, MAX - 1, 1, a, b);
		}
	}
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
