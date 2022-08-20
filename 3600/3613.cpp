#include<iostream>
#include<string>
using namespace std;
int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    string s, ans = "";
    //to prohibit mixed two languages
    int cnt_cpp = 0, cnt_java = 0;
    cin >> s;
    //_..., X..., 
    if (s[0] < 97 || s[s.size() - 1] == '_') {
        cout << "Error!\n";
        return 0;
    }
    for (int i = 0; i < s.size(); i++) {
        if (cnt_cpp != 0 && cnt_java != 0) {
            cout << "Error!\n";
            return 0;
        }
        //a-z
        if (s[i] >= 97 && s[i] <= 122)
            ans += s[i];
        //A-Z
        else if (s[i] <= 90 && s[i] >= 65) {
            if (cnt_cpp != 0) {
                cout << "Error!\n";
                return 0;
            }
            ans += '_';
            ans += tolower(s[i]);
            cnt_java++;
        }
        //cpp style -> java style(toupper)
        else if (s[i] == '_') {
            if (s[i + 1] == '_' || s[i + 1] < 97 || cnt_java != 0) {
                cout << "Error!\n";
                return 0;
            }
            ans += toupper(s[++i]);
            cnt_cpp++;
        }
        else {
            cout << "Error!\n";
            return 0;
        }
    }
    cout << ans;

    return 0;
}
