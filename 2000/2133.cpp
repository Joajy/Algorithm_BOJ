#include<iostream>
using namespace std;

int dp[31]{ 1,0,3 };
int n;

int solution() {
    if (n % 2 == 1) return 0;
    for (int i = 4; i <= n; i++) {
        dp[i] += dp[i - 2] * 3;
        for (int j = 4; j <= i; j += 2)
            dp[i] += dp[i - j] << 1;
    }
    return dp[n];
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> n;
    cout << solution();
    return 0;
}
