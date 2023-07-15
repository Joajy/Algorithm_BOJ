#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

int tree[1'000'001];

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)cin >> tree[i];
    int st = 0, en = *max_element(tree, tree + n), res = 0;

    while (st <= en) {
        ll total = 0;
        int mid = (st + en) >> 1;
        for (int i = 0; i < n; i++)
            if (tree[i] > mid)total += tree[i] - mid;
        if (total >= m) {
            res = mid;
            st = mid + 1;
        }
        else en = mid - 1;
    }
    cout << res;
    return 0;
}
