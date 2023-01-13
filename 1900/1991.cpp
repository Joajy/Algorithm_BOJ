//해당 문제에 대해 2가지 풀이가 있으니 참고하시면 감사하겠습니다. ( line4, line 46)

//1번 풀이(2D char형 배열 풀이)
#include<iostream>
using namespace std;

char alp[26][2];

void preorder(char x) {
    if (x < 'A' || x > 'Z') return;
    cout << x;
    preorder(alp[x - 'A'][0]);
    preorder(alp[x - 'A'][1]);
}
void inorder(char x) {
    if (x < 'A' || x > 'Z') return;
    inorder(alp[x - 'A'][0]);
    cout << x;
    inorder(alp[x - 'A'][1]);
}
void postorder(char x) {
    if (x < 'A' || x > 'Z') return;
    postorder(alp[x - 'A'][0]);
    postorder(alp[x - 'A'][1]);
    cout << x;
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    while (n--) {
        char a, b, c;   //root, left, right
        cin >> a >> b >> c;
        alp[a - 'A'][0] = b;
        alp[a - 'A'][1] = c;
    }
    preorder('A'); cout << '\n';
    inorder('A'); cout << '\n';
    postorder('A');
    return 0;
}

//2번 풀이(map 자료구조 사용)
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
    preorder('A');
    cout << '\n';
    inorder('A');
    cout << '\n';
    postorder('A');
    return 0;
}
