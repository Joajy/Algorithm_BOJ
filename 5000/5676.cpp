#include<iostream>
using namespace std;

const int MAX = 100001;
int n, m, k;
int ar[MAX], seg[MAX << 2];

int change(int x) {
	if (x > 0) return 1;
	if (x == 0) return 0;
	return -1;
}

int init(int st, int en, int node) {
	if (st == en) return seg[node] = ar[st];
	int mid = (st + en) >> 1;
	return seg[node] = init(st, mid, node << 1) * init(mid + 1, en, (node << 1) + 1);
}

int update(int st, int en, int node, int idx, int val) {
	if (idx < st || idx > en) return seg[node];
	if (st == en) return seg[node] = val;
	int mid = (st + en) >> 1;
	return seg[node] = update(st, mid, node << 1, idx, val) * update(mid + 1, en, (node << 1) + 1, idx, val);
}

int mul(int st, int en, int left, int right, int node) {
	if (left > en || right < st) return 1;
	if (left <= st && en <= right) return seg[node];
	int mid = (st + en) >> 1;
	return mul(st, mid, left, right, node << 1) * mul(mid + 1, en, left, right, (node << 1) + 1);
}

void solution() {
	cin >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> ar[i];
		ar[i] = change(ar[i]);
	}
	init(1, n, 1);
	int a, b;
	char cmd;
	string s;
	for (int i = 0; i < k; ++i) {
		cin >> cmd;
		if (cmd == 'C') {
			cin >> a >> b; 
			b = change(b);
			if (ar[a] == b) continue;
			ar[a] = b;
			update(1, n, 1, a, b);
		}
		else {
			cin >> a >> b;
			int tmp = mul(1, n, a, b, 1);
			if (tmp == 1)s += '+';
			else if (tmp == -1) s += '-';
			else s += '0';
		}
	}
	cout << s << '\n';
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	while (cin >> n) {
		solution();
	}
	return 0;
}
