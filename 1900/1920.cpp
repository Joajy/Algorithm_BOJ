#include<iostream>
#include<algorithm>
#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std;

int x[100001]{ 0 };
int main() {
    fast;
    int n, num;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        x[i] = num;
    }
    sort(x, x + n);
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int l = 0, h = n - 1, mid = (l + h) / 2;
        bool t = false;
        cin >> num;
        while (l <= h) {
            if (x[mid] == num) {
                t = true;
                break;
            }
            if (x[mid] < num)
                 l = mid + 1;
            else
                h = mid - 1;
            mid = (l + h) / 2;
        }
        if (t) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
    return 0;
}
