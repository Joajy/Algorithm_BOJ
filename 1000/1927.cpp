#include <iostream>
#include <queue>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, x;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0;i < n;i++) {
        cin >> x;
        if (x == 0) {
            if (q.empty()) {
                cout << 0 << '\n';
                continue;
            }
            cout << q.top() << '\n';
            q.pop();
        }
        else
            q.push(x);
    }
    return 0;
}
