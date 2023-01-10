#include<iostream>    
#include<set>
#include<functional>
#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std;
int main() {
    fast;
    int n;
    string s;
    set<string, greater<string>> name;
    cin >> n; cin.get();
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        if (s.find("enter") != string::npos)
            name.insert(s.substr(0, s.length() - 6));
        else if (s.find("leave") != string::npos)
            name.erase(s.substr(0, s.length() - 6));
    }
    for (auto i : name)
        cout << i << '\n';
    return 0;
}
