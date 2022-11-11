#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left, * right;
};

void preorder(Node* node) {
    if (node == nullptr) return;
    preorder(node->left);
    preorder(node->right);
    cout << node->data << '\n';
}

Node* Insert(Node* node, int data) {
    if (node == nullptr) {
        node = new Node;
        node->data = data;
        node->right = nullptr;
        node->left = nullptr;
    }
    else if (data > node->data)
        node->right = Insert(node->right, data);
    else
        node->left = Insert(node->left, data);
    return node;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int num;
    Node* root = nullptr;
    while (cin >> num) {
        if (num == EOF) break;
        root = Insert(root, num);
    }
    preorder(root);
    return 0;
}
