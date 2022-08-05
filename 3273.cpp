#include<iostream>
#include<algorithm>
using namespace std;

int z[100001];

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    int n, t;
    cin >> n;
    for (int i = 0; i < n; i++)        cin >> z[i];
    sort(z, z + n);
    int x, cnt = 0, Max = n;
    cin >> x;
    for (int i = 0; i < n; i++) {
        if (z[i] + z[i + 1] >= x) {
            Max = i + 1;
            break;
        }
    }
    for (int i = 0; i < Max; i++) {
        for (int j = i + 1; j < n; j++) {
            if (z[i] + z[j] == x) {
                cnt++;
                break;
            }
        }
    }
    cout << cnt;
    return 0;
}