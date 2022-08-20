#include<iostream>
#include<algorithm>
#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int a[1001][3];
int dp[1001][3];

int main() {
    fast;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        fill(dp[i], dp[i] + 3, 1000000);
    }
    dp[1][0] = a[1][0], dp[1][1] = a[1][1], dp[1][2] = a[1][2];
    for (int i = 1; i <= n; i++) {
        dp[i + 1][0] = min(dp[i + 1][0], min(dp[i][1] + a[i + 1][0], dp[i][2] + a[i + 1][0]));
        dp[i + 1][1] = min(dp[i + 1][1], min(dp[i][0] + a[i + 1][1], dp[i][2] + a[i + 1][1]));
        dp[i + 1][2] = min(dp[i + 1][2], min(dp[i][0] + a[i + 1][2], dp[i][1] + a[i + 1][2]));
    }
    int ans = min(dp[n][0], min(dp[n][1], dp[n][2]));
    cout << ans;
    return 0;
}
