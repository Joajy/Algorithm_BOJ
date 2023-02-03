#include<iostream>
#include<map>
using namespace std;

map<string, bool> a;
string s;

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    int n, m, answer = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s;
        a.insert({s, true});
    }
    for (int i = 0; i < m; i++) {
        cin >> s;
        if (a[s]) answer++;
    }
    cout << answer;
    return 0;
}
