#include<iostream>
using namespace std;

int n, m;
int ar[11];
bool vis[11];

void sol(int x) {
    if (x == m) {
        for (int i = 0; i < m; i++)
            cout << ar[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            ar[x] = i;
            vis[i] = true;
            sol(x + 1);
            vis[i] = 0;
        }
    }
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    sol(0);
    return 0;
}