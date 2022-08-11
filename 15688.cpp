//add define tie & sync
#include<iostream>
#include<algorithm>
#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
int ar[1000001];
using namespace std;
int main() {
    fast;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> ar[i];
    sort(ar, ar + n);
    for (int i = 0; i < n; i++)
        cout << ar[i] << '\n';
    return 0;
}

/*
#include<iostream>
#include<algorithm>
int ar[1000001];
using namespace std;
int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> ar[i];
    sort(ar, ar + n);
    for (int i = 0; i < n; i++)
        cout << ar[i] << '\n';
    return 0;
}*/
