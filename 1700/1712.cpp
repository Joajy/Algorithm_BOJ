#include <iostream>
#include <queue>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, x, answer = 0;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0;i < n;i++) {
        cin >> x;
        q.push(x);
    }
    while (q.size() != 1) {
        int sum = q.top();
        q.pop();
        sum += q.top();
        q.pop();
        q.push(sum);
        answer += sum;
    }
    cout << answer;
    return 0;
}
