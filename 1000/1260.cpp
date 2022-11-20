#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> adj[1001];
bool vis[1001];

void dfs(int cur) {
    vis[cur] = 1;
    cout << cur << ' ';
    for (auto i : adj[cur]) {
        if (vis[i]) continue;
        dfs(i);
    }
}
void bfs(int v) {
    queue<int> q;
    q.push(v);
    vis[v] = 1;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        cout << cur << ' ';
        for (auto n : adj[cur]) {
            if (vis[n]) continue;
            vis[n] = 1;
            q.push(n);
        }
    }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, m, v;
    cin >> n >> m >> v;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
        sort(adj[i].begin(), adj[i].end());
    dfs(v);
    cout << '\n';
    fill(vis, vis + 1001, 0);
    bfs(v);
    return 0;
}
