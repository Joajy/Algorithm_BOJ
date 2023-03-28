#include<iostream>
#include<algorithm>
using namespace std;
#define p pair<int, int>
#define MAX 100001
#define INF 2147483647

int arr[MAX];
p segTree[MAX << 2];

p init(int node, int st, int en) {
    if (st == en) return segTree[node] = { arr[st], st };
    int mid = (st + en) >> 1;
    return segTree[node] = min(init(node << 1, st, mid), init((node << 1) + 1, mid + 1, en));
}

p update(int st, int en, int node, int idx, int val) {
    if (idx < st || idx > en) return segTree[node];
    if (st == en) return segTree[node] = { val, st };
    int mid = (st + en) >> 1;
    return segTree[node] = min(update(st, mid, node << 1, idx, val), update(mid + 1, en, (node << 1) + 1, idx, val));
}

p minQ(int st, int en, int node, int left, int right) {
    if (left > en || right < st) return { INF, INF };
    if (left <= st && en <= right) return segTree[node];
    int mid = (st + en) >> 1;
    return min(minQ(st, mid, node << 1, left, right), minQ(mid + 1, en, (node << 1) + 1, left, right));
}

int main() {
    cin.tie(0), cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    init(1, 1, n);
    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
            update(1, n, 1, b, c);
        else
            cout << minQ(1, n, 1, b, c).second << '\n';
    }
    return 0;
}
