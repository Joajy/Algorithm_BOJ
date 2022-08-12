#include<iostream>
#include<queue>
#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std;

int ans[100002];
bool vis[100002];

int main()
{
    fast;
    int n, k;
    cin >> n >> k;
    queue<int> q;
    q.push(n);
    ans[n] = 0;
    vis[n] = 1;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        int move[3] = { cur - 1, cur + 1, 2 * cur };
        for (int i = 0; i < 3; i++) {
            if (move[i] > 100000 || move[i] < 0) continue;
            if (vis[move[i]] && ans[move[i]] <= ans[cur] + 1) continue;
            vis[move[i]] = 1;
            ans[move[i]] = ans[cur] + 1;
            q.push(move[i]);
        }
    }
    cout << ans[k];
    return 0;
}