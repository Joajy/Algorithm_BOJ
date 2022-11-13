#include <iostream>
#include <queue>
using namespace std;
#define ll long long

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t, n, x;
    cin >> t;
    while (t--) {
        ll answer = 0;
        cin >> n;
        priority_queue<ll, vector<ll>, greater<ll>> q;
        for (int i = 0;i < n;i++) {
            cin >> x;
            q.push(x);
        }
        while (q.size() != 1) {
            ll sum = q.top(); q.pop();
            sum += q.top();          q.pop();
            q.push(sum);
            answer += sum;
        }
        cout << answer << '\n';
    }
    return 0;
}
