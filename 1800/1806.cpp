#include<iostream>
#include<algorithm>
#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std;
int a[100006];

int main() {
    fast;
    int n, s, ans = 100000000;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int en = 0, sum = a[0];
    for (int st = 0; st < n; st++) {
        while (en < n && sum < s)
            sum += a[++en];
        if (en == n)
            break;
        ans = min(ans, en - st + 1);
        sum -= a[st];
    }
    if (ans == 100000000) cout << 0;
    else cout << ans;
}