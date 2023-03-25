
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define MAXSIZE 1'000'001

int a[MAXSIZE];
int dp[MAXSIZE];

int main() {
    cin.tie(0), cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n, cnt = 0;
    vector<int> v, ans;
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> a[i];
    v.push_back(a[1]);

    for (int i = 2; i <= n; i++) {
        if (a[i] > v[cnt]) {
            v.push_back(a[i]);
            dp[i] = ++cnt;
        }
        else {
            int idx = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
            v[idx] = a[i];
            dp[i] = idx;
        }
    }

    for (int i = n; i >= 0; i--) {
        if (dp[i] == cnt) {
            ans.push_back(a[i]);
            cnt--;
        }
    }

    int Size = v.size();
    cout << Size << '\n';
    for (int i = 0; i < Size; i++){
         cout << ans.back() << ' ';
         ans.pop_back();
    }
//        cout << ans[Size - i - 1] << ' ';
    return 0;
}
