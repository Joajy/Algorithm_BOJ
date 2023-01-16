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
	//find 함수를 사용하려 했으나 시간초과 발생
	
	//lower_bound는 범위 조건이고 find는 특정 값에 대한 조건이므로 lower_bound가 일반적으로 더 빠르다고 봐야 함
	for (int i = 1; i <= n; i++)
		cout << lower_bound(v.begin(), v.end(), x[i]) - v.begin() << ' ';
	return 0;
}
