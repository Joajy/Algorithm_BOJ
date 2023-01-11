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
        cin >> k; cin.get();
        while (k--) {
            string cmd;
            getline(cin, cmd);
            if (cmd[0] == 'I')
                s.insert(stoi(cmd.substr(2, cmd.length() - 2)));
            else if (cmd == "D 1") {
                if (!s.empty()) {
                    auto it = s.find(*s.rbegin());
                    s.erase(it);
                }
            }
            else if (cmd == "D -1") {
                if (!s.empty())
                    s.erase(s.begin());
            }
        }
        if (s.empty())
            cout << "EMPTY\n";
        else
            cout << *s.rbegin() << ' ' << *s.begin() << '\n';
    }
    return 0;
}
