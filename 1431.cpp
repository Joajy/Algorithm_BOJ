#include<iostream>
#include<utility>
#include<algorithm>
#include<cmath>
#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std;

string s[51];

int main()
{
    fast;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            //first condition
            if (s[i].length() > s[j].length())
                swap(s[i], s[j]);
            else if (s[i].length() == s[j].length()) {
                int a = 0, b = 0;
                for (int k = 0; k < s[i].length(); k++) {
                    if (48 < s[i][k] && s[i][k] < 58)
                        a += s[i][k] - 48;
                    if (48 < s[j][k] && s[j][k] < 58)
                        b += s[j][k] - 48;
                }
                //second condition
                if (a > b)
                    swap(s[i], s[j]);
                else if (a == b) {
                    //third condition -> equal s[i] & s[j] at cond 1, 2
                    for (int k = 0; k < s[i].length(); k++) {
                        if (s[i][k] > s[j][k]) {
                            swap(s[i], s[j]);
                            break;
                        }
                        else if (s[i][k] < s[j][k]) {
                            break;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << s[i] << '\n';
    if (n == 0) cout << 0;
    return 0;
}