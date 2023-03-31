#include<iostream>
using namespace std;
#define MAX 100001

int tree[MAX << 2], lazy[MAX << 2];
int a, b, c, n, m;

void lazyUpdate(int st, int en, int node) {
	if (lazy[node] % 2 == 0) return;
	if (st != en) {
		lazy[node << 1] += lazy[node];
		lazy[(node << 1) + 1] += lazy[node];
	}
	tree[node] = (en - st + 1) - tree[node];
	lazy[node] = 0;
}

int rangeUpdate(int st, int en, int left, int right, int node, int val) {
	lazyUpdate(st, en, node);
	if (left > en || right < st) return tree[node];
	if (left <= st && en <= right) {
		if (st != en) {
			lazy[node << 1] += val;
			lazy[(node << 1) + 1] += val;
		}
		return tree[node] = (en - st + 1) - tree[node];
	}
	int mid = (st + en) >> 1;
	return tree[node] = rangeUpdate(st, mid, left, right, node << 1, val) 
		+ rangeUpdate(mid + 1, en, left, right, (node << 1) + 1, val);
}

int sum(int st, int en, int node, int left, int right) {
	lazyUpdate(st, en, node);
	if (left > en || right < st) return 0;
	if (left <= st && en <= right) return tree[node];
	int mid = (st + en) >> 1;
	return sum(st, mid, node << 1, left, right) + sum(mid + 1, en, (node << 1) + 1, left, right);
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (a == 0)
			rangeUpdate(1, n, b, c, 1, 1);
		else
			cout << sum(1, n, 1, b, c) << '\n';
	}
	return 0;
}
