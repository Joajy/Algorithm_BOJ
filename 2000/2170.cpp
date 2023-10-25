#include<iostream>
#include<algorithm>
using namespace std;

struct Line {
	int st, en;
} line[1000001];

int n;

bool cmp(Line a, Line b) {
	if (a.st < b.st) {
		return true;
	}
	if(a.st == b.st && a.en < b.en){
		return true;
	}
	return false;
}

void input() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> line[i].st >> line[i].en;
	}
}

void solution() {
	input();
	sort(line, line + n, cmp);
	int start = line[0].st, end =line[0].en;
	int answer = 0;
	for (int i = 1; i < n; ++i) {
		//완전히 겹치는 경우
		if (line[i].en <= end) continue;
		if (end >= line[i].st) {
			end = line[i].en;
		}
		else {
			answer += end - start;
			start = line[i].st;
			end = line[i].en;
		}
	}
	answer += end - start;
	cout << answer;
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
