//1번째 풀이방법 7580KB, 40ms

#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
int main() {
    fast;
    int n, m, cnt = 0;
    cin >> n >> m;
    string tmp;
    set<string> t;
    vector <string> v;
    for (int i = 0; i < max(n, m); i++) {
        cin >> tmp;
        t.insert(tmp);
    }
    for (int i = 0; i < min(n, m); i++) {
        cin >> tmp;
        auto iter = t.find(tmp);
        if (iter != t.end()) {
            cnt++;
            v.push_back(*iter);
        }
    }
    sort(v.begin(), v.end());
    cout << cnt << '\n';
    for (auto i : v)
        cout << i << '\n';
    return 0;
}

//2번째 풀이방법  9864KB, 60ms

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int main() {
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
	int n, m;
	string name;
	cin >> n >> m;
	priority_queue<string> a, b;
	vector<string> v;
	for (int i = 0; i < n; i++) {
		cin >> name;
		a.push(name);
	}
	for (int i = 0; i < m; i++) {
		cin >> name;
		b.push(name);
	}
	while (!(a.empty() || b.empty())) {
		if (a.top() == b.top()) {
			v.push_back(a.top());
			a.pop(); b.pop();
		}
		else if (a.top() > b.top()) a.pop();
		else b.pop();
	}
	reverse(v.begin(), v.end());
	cout << v.size() << '\n';
	for (auto i : v) cout << i << '\n';
	return 0;
}
