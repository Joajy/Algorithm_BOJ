#include<iostream>
#include<utility>
#include<algorithm>
#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std;
pair<int, int> a[100006];

int main() {
    fast;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i].second >> a[i].first;
    sort(a, a + n);
    int ans = 1, t = a[0].first;
    for (int i = 1; i < n; i++) {
        if (t <= a[i].second) {
            ans++;
            t = a[i].first;
        }
    }
    cout << ans;
}