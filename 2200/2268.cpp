#include<iostream>
using namespace std;
#define ll long long

int arr[1 << 20];
ll tree[1 << 22];
int n, q, a, b, c;

ll init(int idx, int st, int en) {
    if (st == en) return tree[idx] = arr[st];
    int mid = (st + en) >> 1;
    return tree[idx] = init(idx << 1, st, mid) + init((idx << 1) + 1, mid + 1, en);
}

ll sum(int st, int en, int idx, int left, int right) {
    if (left > en || right < st) return 0;
    if (left <= st && en <= right) return tree[idx];
    int mid = (st + en) >> 1;
    return sum(st, mid, idx << 1, left, right) + sum(mid + 1, en, (idx << 1) + 1, left, right);
}

ll update(int st, int en, int node, int idx, ll tmp) {
    if (idx < st || idx > en) return tree[node];
    if (st == en) return tree[node] = tmp;
    int mid = (st + en) >> 1;
    return tree[node] = update(st, mid, node << 1, idx, tmp) + update(mid + 1, en, (node << 1) + 1, idx, tmp);
}

int main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 0; i < q; i++) {
        cin >> a >> b >> c;
        int Max = b > c ? b : c;
        int Min = b < c ? b : c;
        if(a == 0) cout << sum(1, n, 1, Min, Max) << '\n';
        else update(1, n, 1, b, c);
    }
    return 0;
}
