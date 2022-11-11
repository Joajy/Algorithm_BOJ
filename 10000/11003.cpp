#include <iostream>
#include <queue>
using namespace std;
#define p pair<int, int>

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, l;
    cin >> n >> l;
    priority_queue<p, vector<p>, greater<p>> q;
    for (int i = 0;i < n;i++) {
        int t;
        cin >> t;
        int bound = i - l + 1;
        q.push({ t, i });
        while (q.top().second < bound)
            q.pop();
        cout << q.top().first << ' ';
    }
    return 0;
}
