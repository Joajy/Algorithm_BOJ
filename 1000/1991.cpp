#include <iostream>
#include <map>
#include <utility>
using namespace std;

map<char, pair<char, char>> m;

void preorder(char node) {
    cout << node;
    if (m[node].first != '.')
        preorder(m[node].first);
    if (m[node].second != '.')
        preorder(m[node].second);
}
void inorder(char node) {
    if (m[node].first != '.')
        inorder(m[node].first);
    cout << node;
    if (m[node].second != '.')
        inorder(m[node].second);
}
void postorder(char node) {
    if (m[node].first != '.')
        postorder(m[node].first);
    if (m[node].second != '.')
        postorder(m[node].second);
    cout << node;
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    char a, b, c;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        m[a] = make_pair(b, c);
    }
    preorder('A'); cout << '\n';
    inorder('A'); cout << '\n';
    postorder('A');
    return 0;
}
