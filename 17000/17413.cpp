#include<iostream>
#include<vector>
#include<utility>
#include<string>
#include<algorithm>
#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std;

int main() {
    fast;
    string s, tmp;
    bool spacing = false;
    getline(cin, s);
    vector<pair<string, bool>> v;   //true(1) -> reverse
    for (char i : s) {
        if (i == '<') {
            spacing = true;
            v.push_back({tmp, 1});
            tmp.clear();
            tmp += i;
        }
        else if (i == ' ') {
            if (spacing == true) {
                tmp += i;
                continue;
            }
            v.push_back({ tmp, 1 });
            tmp.clear();
            v.push_back({ " ", 0 });
        }
        else if (i == '>') {
            spacing = false;
            tmp += i;
            v.push_back({ tmp, 0 });
            tmp.clear();
        }
        else
            tmp += i;
    }
    if (tmp != "")
        v.push_back({ tmp, 1 });
    for (int i = 0; i < v.size(); i++) {
        if (v.at(i).second == 1)
            reverse(v.at(i).first.begin(), v.at(i).first.end());
        cout << v.at(i).first;
    }
    return 0;
}
