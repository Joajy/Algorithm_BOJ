#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 100001
int coin[100];
int dp[10001];

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    fill(dp + 1, dp + k + 1, MAX);
    for (int i = 0; i < n; i++) cin >> coin[i];
    for (int i = 0; i < n; i++) {
        for (int idx = coin[i]; idx <= k; idx++)
            dp[idx] = min(dp[idx - coin[i]] + 1, dp[idx]);
    }
    if (dp[k] == MAX) dp[k] = -1;
    cout << dp[k];
    return 0;
}
