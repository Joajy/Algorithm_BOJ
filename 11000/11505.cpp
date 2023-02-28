#include<iostream>
using namespace std;
#define MAX 1000001
#define ll long long
#define DIV 1000000007

int arr[MAX];
ll tree[MAX << 2];
int n, m, k, a, b;
ll c;

ll init(int idx, int st, int en) {
    if (st == en) return tree[idx] = arr[st];
    int mid = (st + en) >> 1;
    return tree[idx] = init(idx << 1, st, mid) * init((idx << 1) + 1, mid + 1, en) % DIV;
}

ll mul(int st, int en, int idx, int left, int right) {
    if (left > en || right < st) return 1;
    if (left <= st && en <= right) return tree[idx];
    int mid = (st + en) >> 1;
    return mul(st, mid, idx << 1, left, right) * mul(mid + 1, en, (idx << 1) + 1, left, right) % DIV;
}

ll update(int st, int en, int node, int idx, ll after) {
    if (idx < st || idx > en) return tree[node];
    if (st == en) return tree[node] = after;
    int mid = (st + en) >> 1;
    return tree[node] = update(st, mid, node << 1, idx, after) * update(mid + 1, en, (node << 1) + 1, idx, after) % DIV;
}

int main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    init(1, 1, n);
    for (int i = 0; i < m + k; i++) {
        cin >> a >> b >> c;
        if (a == 1)
            update(1, n, 1, b, c);
        else if (a == 2)
            cout << mul(1, n, 1, b, c) << '\n';
    }
    return 0;
}
