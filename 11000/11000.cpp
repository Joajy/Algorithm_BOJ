#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
#define p pair<int, int>
#define s first
#define e second

int n;
p lecture[200000];

void input() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> lecture[i].s >> lecture[i].e;
	}
}

void solution() {
	input();
	sort(lecture, lecture + n);
	priority_queue<int> pq;
	pq.push(-lecture[0].e);
	for (int i = 1; i < n; ++i) {
		int st = -lecture[i].s;
		int en = -lecture[i].e;
		if (-pq.top() > -st) {
			pq.push(en);
		}
		else {
			pq.pop();
			pq.push(en);
		}
	}
	cout << pq.size();
}

int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
