#include<iostream>
#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
long dp[100001]{ 0 };
int a[100001];
int main() {
    fast;
    int n, m, x, y;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dp[i + 1] += dp[i] + a[i];
    }
    for (int z = 0; z < m; z++) {
        cin >> x >> y;
        if (x == y) {
            cout << a[x - 1] << '\n';
            continue;
        }
        cout << dp[y] - dp[x - 1] << '\n';

    }
    return 0;
}
