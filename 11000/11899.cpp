#include<iostream>
#include<stack>
using namespace std;

void solution() {
	string str;
	cin >> str;
	stack<char> s;
	s.push(str[0]);
	for (int i = 1; i < str.length();++i) {
		if (s.empty()) s.push(str[i]);
		else if(s.top() == '(' && str[i] == ')'){
			s.pop();
		}
		else {
			s.push(str[i]);
		}
	}
	cout << s.size();
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
