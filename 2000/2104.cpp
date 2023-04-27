#include<iostream>
#define p pair<int, int>
#define ll long long
#define MAX 100001
using namespace std;

int n;
ll arr[MAX], addSeg[MAX << 2], minSeg[MAX << 2];
ll answer = 0;

ll min(ll a, ll b) {return a < b ? a : b;}

ll max(ll a, ll b) {return a > b ? a : b;}

ll cmpNode(int a, int b) {
	if (a == -1) return b;
	if (b == -1) return a;
	if (arr[a] < arr[b]) return a;
	return b;
}

ll initSum(int st, int en, int node) {
	if (st == en) return addSeg[node] = arr[st];
	int mid = (st + en) >> 1;
	return addSeg[node] = initSum(st, mid, node << 1) + initSum(mid + 1, en, (node << 1) + 1);
}

ll initMin(int st, int en, int node) {
	if (st == en) return minSeg[node] = st;
	int mid = (st + en) >> 1;

	ll a = initMin(st, mid, node << 1);
	ll b = initMin(mid + 1, en, (node << 1) + 1);

	return minSeg[node] = cmpNode(a, b);
}

ll minQ(int st, int en, int left, int right, int node) {
	if (left > en || right < st) return -1;
	if (left <= st && en <= right) return minSeg[node];
	int mid = (st + en) >> 1;
	ll a = minQ(st, mid, left, right, node << 1);
	ll b = minQ(mid + 1, en, left, right, (node << 1) + 1);

	return cmpNode(a, b);
}

ll sumQ(int st, int en, int left, int right, int node) {
	if (left > en || right < st) return 0;
	if (left <= st && en <= right) return addSeg[node];
	int mid = (st + en) >> 1;
	return sumQ(st, mid, left, right, node << 1) + sumQ(mid + 1, en, left, right, (node << 1) + 1);
}

ll query(int st, int en) {
	if (st == en) return arr[st] * arr[st];
	int node = minQ(1, n, st, en, 1);
	ll res = arr[node] * sumQ(1, n, st, en, 1);
	if (st < node) res = max(res, query(st, node - 1));
	if (en > node) res = max(res, query(node + 1, en));
	return res;
}

void input() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
}

void solution() {
	input();
	initSum(1, n, 1);
	initMin(1, n, 1);
	cout << query(1, n);
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
