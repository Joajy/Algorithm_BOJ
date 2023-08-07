#include<iostream>
using namespace std;
#define MID (st + en) >> 1

const int MAX = 100001;
int n, m;
int ar[MAX];
int segOdd[MAX << 2], segEven[MAX << 2];


int initOdd(int st, int en, int node) {
	if (st == en) return segOdd[node] = ar[st] % 2;
	int mid = MID;
	return segOdd[node] = initOdd(st, mid, node << 1) + initOdd(mid + 1, en, (node << 1) + 1);
}

int initEven(int st, int en, int node) {
	if (st == en) return segEven[node] = (ar[st] + 1) % 2;
	int mid = MID;
	return segEven[node] = initEven(st, mid, node << 1) + initEven(mid + 1, en, (node << 1) + 1);
}

int updateOdd(int st, int en, int node, int idx, int val) {
	if (idx < st || idx > en) return segOdd[node];
	if (st == en) return segOdd[node] += val;
	int mid = MID;
	return segOdd[node] = updateOdd(st, mid, node << 1, idx, val) + updateOdd(mid + 1, en, (node << 1) + 1, idx, val);
}

int updateEven(int st, int en, int node, int idx, int val) {
	if (idx < st || idx > en) return segEven[node];
	if (st == en) return segEven[node] += val;
	int mid = MID;
	return segEven[node] = updateEven(st, mid, node << 1, idx, val) + updateEven(mid + 1, en, (node << 1) + 1, idx, val);
}

int queryEven(int st, int en, int left, int right, int node) {
	if (left > en || right < st) return 0;
	if (left <= st && en <= right) return segEven[node];
	int mid = MID;
	return queryEven(st, mid, left, right, node << 1) + queryEven(mid + 1, en, left, right, (node << 1) + 1);
}

int queryOdd(int st, int en, int left, int right, int node) {
	if (left > en || right < st) return 0;
	if (left <= st && en <= right) return segOdd[node];
	int mid = MID;
	return queryOdd(st, mid, left, right, node << 1) + queryOdd(mid + 1, en, left, right, (node << 1) + 1);
}

void input() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> ar[i];
		ar[i] %= 2;
	}
	cin >> m;
}

void solution() {
	input();
	initOdd(1,n,1);
	initEven(1,n,1);
	int cmd, l, r;
	for (int i = 0; i < m; ++i) {
		cin >> cmd >> l >> r;
		if (cmd == 1) {
			int x = r % 2;
			if (x == 0) {
				if (ar[l] == x) continue;
				ar[l] = x;
				updateOdd(1, n, 1, l, -1);
				updateEven(1, n, 1, l, 1);
			}
			else{
				if (ar[l] == x) continue;
				ar[l] = x;
				updateOdd(1, n, 1, l, 1);
				updateEven(1, n, 1, l, -1);
			}
		}
		else if (cmd == 2) {
			cout << queryEven(1, n, l, r, 1) << '\n';
		}
		else {
			cout << queryOdd(1, n, l, r, 1) << '\n';
		}
	}
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
