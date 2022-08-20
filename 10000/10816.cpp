#include<iostream>
#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std;

int x[20000001];

int main() {
    fast;
    int n, m, t;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        x[t + 10000000]++;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> t;
        cout << x[t + 10000000] << ' ';
    }
    return 0;
}
