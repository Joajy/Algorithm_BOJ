#include<iostream>
#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main() {
    fast;
    long long dp[91]{ 0,1,1,2,3 };
    int n;
    cin >> n;
    for (int i = 2; i < n - 1; i++) 
        dp[i + 2] = dp[i] + dp[i + 1];
    cout << dp[n];
    return 0;
}