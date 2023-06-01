#include<iostream>
#include<vector>
using namespace std;
#define MAX 50
int n, del, answer = 0;

struct Node {
	bool isDel = false;
	int par = -1;
	vector<int> child;
}node[MAX + 1];

void input() {
	cin >> n;
	int p;
	for (int i = 1; i <= n; ++i) {
		cin >> p;
		node[i].par = p + 1;
		node[p + 1].child.push_back(i);
	}
	cin >> del;
	++del;
}

void delNode(Node *pNode) {
	if (pNode->isDel == true) return;
	pNode->isDel = true;
	for (int i = 0; i < pNode->child.size(); ++i) {
		delNode(&node[pNode->child[i]]);
	}
	pNode->child.clear();
}

void search(Node pNode) {
	if (pNode.child.empty() && pNode.isDel == false) {
		++answer;
		return;
	}
	for (int i = 0; i < pNode.child.size(); ++i) {
		search(node[pNode.child[i]]);
	}
}

void solution() {
	input();
	if (node[node[del].par].child.size() == 1) {
		node[node[del].par].child.clear();
	}
	delNode(&node[del]);
	for (auto i : node[0].child) {
		search(node[i]);
	}
	cout << answer;
}

int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
