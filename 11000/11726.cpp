#include<iostream>
#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
long long dp[1001]{ 0,1,2,3 };

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i < n - 1; i++) {
        dp[i + 2] = (dp[i] + dp[i + 1]) % 10007;
    }
    cout << dp[n];
    return 0;
}
