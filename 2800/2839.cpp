#include<iostream>
using namespace std;

int main() {
    int n, ans = 0;
    cin >> n;
    int cnt = n;
    while (cnt >= 5) {
        cnt -= 5;
        ans++;
    }
    if (cnt == 0) {
        cout << ans;
        return 0;
    }
    else {
        while (cnt % 3 != 0) {
            cnt += 5;
            ans--;
            if (cnt > n) {
                cout << -1;
                return 0;
            }
        }
        ans += cnt / 3;
    }
    cout << ans;
    return 0;
}
