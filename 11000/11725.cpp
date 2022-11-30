#include <iostream>
#include <vector>
using namespace std;

int par[100001];
vector<int> node[100001];

void dfs(int cur) {
    for (int child : node[cur]) {
        if (par[cur] == child) continue;
        par[child] = cur;
        dfs(child);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, a, b;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        node[a].push_back(b);
        node[b].push_back(a);
    }
    dfs(1);
    for (int i = 2; i <= n; i++)
        cout << par[i] << '\n';
    return 0;
}
