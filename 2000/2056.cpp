#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int work[10001], indeg[10001], dp[10001];
vector<int> v[10001];

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int z = 1; z <= n; z++) {
        int cnt, nxt;
        cin >> work[z] >> cnt;
        while (cnt--) {
            cin >> nxt;
            v[z].push_back(nxt);
            indeg[nxt]++;
        }
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) q.push(i);
        dp[i] = work[i];
    }
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (auto nxt : v[cur]) {
            indeg[nxt]--;
            dp[nxt] = max(dp[nxt], dp[cur] + work[nxt]);
            if (indeg[nxt] == 0) q.push(nxt);
        }
    }
    int answer = dp[0];
    for (int i = 1; i <= n; i++)
        answer = max(answer, dp[i]);
    cout << answer;
    return 0;
}
