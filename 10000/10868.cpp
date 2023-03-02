#include<iostream>
#include<algorithm>
using namespace std;
#define MAXINT 2147483647

int arr[1 << 17];
int minTree[1 << 19];
int n, m , a, b, c;

int initMin(int idx, int st, int en) {
	if (st == en) return minTree[idx] = arr[st]; // leaf
	int mid = (st + en) >> 1;
	return minTree[idx] = min(initMin(idx << 1, st, mid), initMin((idx << 1) + 1, mid + 1, en));
}

int findMin(int st, int en, int idx, int left, int right) {
	if (left > en || right < st) return MAXINT;
	if (left <= st && en <= right) return minTree[idx];
	int mid = (st + en) >> 1;
	return min(findMin(st, mid, idx << 1, left, right), findMin(mid + 1, en, (idx << 1) + 1, left, right));
}

int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	initMin(1, 1, n);
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		cout << findMin(1, n, 1, a, b) << '\n';
	}
	return 0;
}
