#include<iostream>
#include<utility>
#include<vector>
#include<stack>
#define x first
#define y second
using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
bool vis[102];
vector<pair<int, int>> connect;

//DFS ����� ����Ͽ����ϴ�.
int main() {
	int n, m;
	cin >> n >> m;
	//vector�� ����� �� ��带 ǥ���մϴ�(���� ��ü)
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		connect.push_back({ a, b });
	}
	int cnt = 0;
	stack<int> s;
	vis[1] = true;
	s.push(1);
	//���ǿ� ���� �ʱⰪ 1�� ������ ����, 1���� �󿡼� DFS�� �����Ͽ� ���ǿ� ���� ��� cnt++ �� stack�� push�մϴ�.
	while (!s.empty()) {
		int cur = s.top(); s.pop();
		for (int i = 0; i < connect.size(); i++) {
			if (connect[i].x == cur && !vis[connect[i].y]) {
				cnt++;
				vis[connect[i].y] = true;
				s.push(connect[i].y);
			}
			else if (connect[i].y == cur && !vis[connect[i].x]) {
				cnt++;
				vis[connect[i].x] = true;
				s.push(connect[i].x);
			}
		}
	}
	//���ϴ� ��� ���
	cout << cnt;
	return 0;
}