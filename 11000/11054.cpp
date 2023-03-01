#include<iostream>
#include<algorithm>
using namespace std;
#define MAX_N 1001
int n;
int a[MAX_N];
int dp[MAX_N], rdp[MAX_N];

int main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
    cin >> n;
    fill(dp, dp + n + 1, 1);
    fill(rdp, rdp + n + 1, 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++)
            if (a[i] < a[j] && dp[i] + 1 > dp[j]) dp[j] = dp[i] + 1;
    }
    for (int i = n; i >= 1; i--) {
        for (int j = i - 1; j >= 1; j--)
            if (a[i] < a[j] && rdp[i] + 1 > rdp[j]) rdp[j] = rdp[i] + 1;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (ans < dp[i] + rdp[i] - 1) ans = dp[i] + rdp[i] - 1;
    cout << ans;
    return 0;
}
