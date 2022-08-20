#include<iostream>
#include<algorithm>
#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std;
int a[100006];

int main() {
    fast;
    int n, ans = 0;
    cin >> n;
    int neg = 0, pos = 0, zero = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < 0) neg++;
        else if (a[i] > 0) pos++;
        else zero++;
    }
    if (n == 1) {
        cout << a[0];
        return 0;
    }
    sort(a, a + n);
    //0 홀짝 개수 여부에 따라 나눔
    if (zero % 2 == 0) {
        //음수가 2k개 있을 때
        if (neg % 2 == 0) {
            for (int i = 0; i < neg; i += 2)
                ans += a[i] * a[i + 1];
            //양수는 2k + 1개 있을 때
            if (pos % 2 == 1)
                ans += a[neg++ + zero];
            for (int i = n - 1; i >= neg + zero; i -= 2) {
                if (a[i] == 1 || a[i - 1] == 1)
                    ans += a[i] + a[i - 1];
                else
                    ans += a[i] * a[i - 1];
            }
        }
        else {
            for (int i = 0; i < neg - 1 + zero; i += 2)
                ans += a[i] * a[i + 1];
            if (zero == 0)
                ans += a[neg - 1];
            if (pos % 2 == 1)
                ans += a[neg++ + zero];
            for (int i = n - 1; i >= neg + zero; i -= 2) {
                if (a[i] == 1 || a[i - 1] == 1)
                    ans += a[i] + a[i - 1];
                else
                    ans += a[i] * a[i - 1];
            }
        }
    }
    //0이 홀수 개 있을 때
    else {
        //음수가 2k개 있을 때
        if (neg % 2 == 0) {
            for (int i = 0; i < neg; i += 2)
                ans += a[i] * a[i + 1];
            if (pos % 2 == 1)
                ans += a[neg++ + zero];
            for (int i = n - 1; i >= neg + zero; i -= 2) {
                if (a[i] == 1 || a[i - 1] == 1)
                    ans += a[i] + a[i - 1];
                else
                    ans += a[i] * a[i - 1];
            }
        }
        //음수가 2k + 1개 있을 때
        else {
            for (int i = 0; i < neg - 1 + zero; i += 2)
                ans += a[i] * a[i + 1];
            if (zero == 0)
                ans += a[neg - 1];
            if (pos % 2 == 1)
                ans += a[neg++ + zero];
            for (int i = n - 1; i >= neg + zero; i -= 2) {
                if (a[i] == 1 || a[i - 1] == 1)
                    ans += a[i] + a[i - 1];
                else
                    ans += a[i] * a[i - 1];
            }
        }
    }
    cout << ans;
}