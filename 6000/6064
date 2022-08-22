#include<iostream>
#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std;

int main() {
    fast;
    int t;
    cin >> t;
    while (t--) {
        int m, n, x, y, ans = 1;
        cin >> m >> n >> x >> y;
        if (m > n) {
            while (x != 1) {
                if (y == 1)
                    y = n;
                else y--;
                x--; ans++;
            }
            int cnt = 0;
            while (cnt <= n && y != 1) {
                cnt++; ans += m;
                y -= m - n;
                if (y == 0)
                    y = n;
                else if (y < 0) {
                    while (y <= 0)
                        y += n;
                    y %= n;
                }
            }
            if (cnt > n)
                cout << -1 << '\n';
            else
                cout << ans << '\n';
        }
        else {
            while (y != 1) {
                if (x == 1)
                    x = m;
                else
                    x--;
                y--; ans++;
            }
            int cnt = 0;
            while (cnt <= m && x != 1) {
                cnt++; ans += n;
                x -= n - m;
                if (x == 0)
                    x = m;
                else if (x < 0) {
                    while (x <= 0)
                        x += m;
                    x %= m;
                }
            }
            if (cnt > m)
                cout << -1 << '\n';
            else
                cout << ans << '\n';
        }
    }
}
