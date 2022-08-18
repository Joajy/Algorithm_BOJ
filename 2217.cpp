#include<iostream>
#include<algorithm>
#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int a[100001];

int main() {
    fast;
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < n; i++)
        ans = max(ans, a[i] * (n - i));
    cout << ans;
    return 0;
}