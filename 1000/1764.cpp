#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
int main() {
    fast;
    int n, m, cnt = 0;
    cin >> n >> m;
    string tmp;
    set<string> t;
    vector <string> v;
    for (int i = 0; i < max(n, m); i++) {
        cin >> tmp;
        t.insert(tmp);
    }
    for (int i = 0; i < min(n, m); i++) {
        cin >> tmp;
        auto iter = t.find(tmp);
        if (iter != t.end()) {
            cnt++;
            v.push_back(*iter);
        }
    }
    sort(v.begin(), v.end());
    cout << cnt << '\n';
    for (auto i : v)
        cout << i << '\n';
    return 0;
}
