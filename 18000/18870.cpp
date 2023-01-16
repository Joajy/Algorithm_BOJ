#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int x[1000001];

int main() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
		v.push_back(x[i]);
	}
  
  //분류하기 -> 정렬 후 중복 값 제거
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
  
  //lower_bound 사용으로 각 항목에 대한 인덱스 추출
	for (int i = 1; i <= n; i++)
		cout << lower_bound(v.begin(), v.end(), x[i]) - v.begin() << ' ';
	return 0;
}
