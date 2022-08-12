#include<iostream>
#include<utility>
#include<algorithm>
#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define f first
#define s second
using namespace std;
using ll = long long;
pair<int, ll> card[100001];
int main()
{
    fast;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> card[i].s;
        card[i].f = 1;
    }
    sort(card, card + n);
    for (int i = 0; i < n; i++) {
        ll z = card[i].s;
        int k = i;
        while (z == card[i + 1].s) {
            card[k].f++;
            i++;
        }
    }
    sort(card, card + n);
    ll ans = card[n - 1].s;
    for (int i = n - 1; i > 0; i--) {
        if (card[i].f == card[i - 1].f) {
            ans = min(card[i].s, card[i - 1].s);
        }
        else
            break;
    }
    cout << ans;
    return 0;
}