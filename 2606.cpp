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

//DFS 방식을 사용하였습니다.
int main() {
	int n, m;
	cin >> n >> m;
	//vector에 연결된 두 노드를 표시합니다(간선 대체)
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		connect.push_back({ a, b });
	}
	int cnt = 0;
	stack<int> s;
	vis[1] = true;
	s.push(1);
	//조건에 따라 초기값 1을 대입한 이후, 1차원 상에서 DFS를 실행하여 조건에 맞을 경우 cnt++ 및 stack에 push합니다.
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
	//원하는 결과 출력
	cout << cnt;
	return 0;
}