#include<iostream>
#include<set>
#include<string>
#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std;

int main() {
    fast;
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        multiset<int> s;
        int k;
        cin >> k;
        while (k--) {
            char cmd;
            int num;
            cin >> cmd >> num;
            if (cmd == 'I')
                s.insert(num);
            else {
                if (s.empty()) continue;
                if (num == 1)
                    s.erase(prev(s.end()));
                else
                    s.erase(s.begin());
            }
        }
        if (s.empty())
            cout << "EMPTY\n";
        else
            cout << *prev(s.end()) << ' ' << *s.begin() << '\n';
    }
    return 0;
}
