#include<iostream>
using namespace std;
int main() {
    int t, x, y, cur;
    cin >> t;
    while (t--) {
        int a, b = 0;
        cin >> x >> y >> cur;
        if (cur % x == 0)
            a = x;
        else
            a = cur % x;
        while (cur > 0) {
            cur -= x;
            b++;
        }
        if (b > 9) {
            cout << a << b << '\n';
        }
        else {
            cout << a << 0 << b << '\n';
        }
    }
    return 0;
}
