#include<iostream>
#include<utility>
#include<algorithm>
#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std
;//name, book count
pair<string, int> x[1001]; 
int main() {
    fast;
    int n;
    cin >> n;
    string t;
    //input
    for (int i = 0; i < n; i++) {
        cin >> t;
        x[i] = { t, 1 };
        for (int j = 0; j < i; j++) {
            if (x[j].first == t) {
                x[j].second++;
                x[i--] = { "",0 };
                n--;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (x[i].second == 0) continue;
        for (int j = i + 1; j < n; j++) {
            if (x[j].second == 0) continue;
           //sorting by count
            if (x[i].second < x[j].second)
                swap(x[i], x[j]);
            //sorting by name alphabetically
            if (x[i].second == x[j].second) {
                for (int k = 0; k < max(x[i].first.length(), x[j].first.length()); k++) {
                    if (x[i].first[k] > x[j].first[k]) {
                        swap(x[i], x[j]);
                        break;
                    }
                    else if (x[i].first[k] < x[j].first[k])
                        break;
                }
            }
        }
    }
    cout << x[0].first;
    return 0;
}
