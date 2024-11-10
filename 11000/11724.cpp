#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

vector<int> v[1001];
bool vis[1001];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, m, ans = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        ans++;
        queue<int> q;
        q.push(i);
        vis[i] = 1;
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (auto n : v[cur]) {
                if (vis[n]) continue;
                vis[n] = 1;
                q.push(n);
            }
        }
    }
    cout << ans;
    return 0;
}


//2. Union-Find
// #include<iostream>
// #define fastio cin.tie(0), ios_base::sync_with_stdio(0);

// using namespace std;

// int n, m;
// int par[1001];

// int find(int cur) {
// 	if (par[cur] == cur) return cur;
// 	return par[cur] = find(par[cur]);
// }

// void input() {
// 	cin >> n >> m;
// 	for (int i = 1; i <= n; ++i) {
// 		par[i] = i;
// 	}
// 	int a, b;
// 	for (int i = 0; i < m; ++i) {
// 		cin >> a >> b;
// 		a = find(a);
// 		b = find(b);
// 		if (a == b) continue;
// 		par[a] = b;
// 	}
// }

// void solution() {
// 	int answer = 0;
// 	for (int i = 1; i <= n; ++i) {
// 		if (par[i] == i) ++answer;
// 	}
// 	cout << answer << '\n';
// }


// int main() {
// 	fastio;
// 	input();
// 	solution();
// 	return 0;
// }
