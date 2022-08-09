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
        ar[x] = i;
        sol(x + 1);
    }
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    sol(0);
    return 0;
}