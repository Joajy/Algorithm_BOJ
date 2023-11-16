#include<iostream>
#include<stack>
using namespace std;
#define p pair<int, int>

int n;
stack<p> s;

void solution() {
	cin >> n;
	s.push(make_pair(1 << 29, 0));
	for (int i = 1; i <= n; ++i) {
		int h;
		cin >> h;
		while (s.top().first < h) {
			s.pop();
		}
		cout << s.top().second << ' ';
		s.push(make_pair(h, i));
	}
}

int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
	solution();
	return 0;
}

/*
#include<cstdio>
#include<stack>
using namespace std;

class P {
public:
	int height;
	int index;
	P(int a, int b) {
		height = a;
		index = b;
	}

	bool compare(int b) {
		if (this->height <= b) {
			return true;
		}
		return false;
	}
};

int n, h;

void solution() {
	scanf("%d", &n);
	stack<P> s;
	s.push(P(1e9, 0));
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &h);
		while (s.top().compare(h)) {
			s.pop();
		}
		printf("%d ", s.top().index);
		s.push(P(h, i));
	}
}

int main() {
	solution();
	return 0;
}
*/
