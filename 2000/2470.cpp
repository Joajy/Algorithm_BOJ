#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    int st = 0, en = n - 1, ans1 = 0, ans2 = n - 1;
    while (st < en) {
        int sum = a[st] + a[en];
        if (abs(sum) < abs(a[ans1] + a[ans2])) {
            ans1 = st; ans2 = en;
            if (sum == 0) break;
        }
        if (sum < 0) st++;
        else en--;
    }
    cout << a[ans1] << ' ' << a[ans2];
    return 0;
}
