#include<iostream>
int ar[2000002];
using namespace std;
int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    int n, t, Max = 0;
    cin >> n;
    for (n; n > 0; n--) {
        cin >> t;
        ar[t + 1000000]++;
        Max = max(Max, t + 1000000);
    }
    for (int i = 0; i <= Max; i++) {
        if (ar[i] != 0) {
            while (ar[i]-- > 0) {
                cout << i - 1000000 << '\n';
            }
        }
    }
    return 0;
}