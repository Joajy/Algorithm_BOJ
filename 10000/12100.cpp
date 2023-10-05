#include<iostream>
#include<vector>
#include<queue>
#define V vector<vector<int>>
using namespace std;

int n, m, answer = 0;
V a;// a[20][20]
int dx[]{ 0,0,-1,1 };
int dy[]{ -1,1,0,0 };

void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void input() {
	cin >> n;
	int num;
	for (int i = 0; i < n; ++i) {
		vector<int> v;
		for (int j = 0; j < n; ++j) {
			cin >> num;
			v.push_back(num);
		}
		a.push_back(v);
	}
}

void getMax(V calculate) {
	for (vector<int> i : calculate) {
		for (int j : i) {
			if (j > answer) answer = j;
		}
	}
}

//해당 방향으로 모은다
//더한다
//다시 해당 방향으로 모은다

V left(V arr) {
	for (int i = 0; i < n; ++i) {
		vector<int> tmp;
		for (int j : arr[i]) {
			if (j == 0) continue;
			tmp.push_back(j);
		}
		while (tmp.size() < n) {
			tmp.push_back(0);
		}
		arr[i] = tmp;
	}
	for (int i = 0; i < n; ++i) {
		vector<int> tmp;
		for (int j = 0; j < n; ++j) {
			if (arr[i][j] == 0) {
				tmp.push_back(0);
			}
			else if (j < n - 1 && arr[i][j] == arr[i][j + 1]) {
				int sum = arr[i][j] << 1;
				tmp.push_back(sum);
				++j;
			}
			else {
				tmp.push_back(arr[i][j]);
			}
		}
		while (n != tmp.size()) {
			tmp.push_back(0);
		}
		arr[i] = tmp;
	}
	for (int i = 0; i < n; ++i) {
		vector<int> tmp;
		for (int j : arr[i]) {
			if (j == 0) continue;
			tmp.push_back(j);
		}
		while (tmp.size() < n) {
			tmp.push_back(0);
		}
		arr[i] = tmp;
	}
	return arr;
}

V right(V arr) {
	for (int i = 0; i < n; ++i) {
		vector<int> tmp, ins;
		for (int j : arr[i]) {
			if (j == 0) continue;
			tmp.push_back(j);
		}
		int size = n - tmp.size();
		while (size--) {
			ins.push_back(0);
		}
		for (int j : tmp) {
			ins.push_back(j);
		}
		arr[i] = ins;
	}
	for (int i = 0; i < n; ++i) {
		vector<int> tmp, ins;
		for (int j = n - 1; j >= 0; --j) {
			if (arr[i][j] == 0) {
				tmp.push_back(0);
			}
			else if (j > 0 && arr[i][j] == arr[i][j - 1]) {
				int sum = arr[i][j] << 1;
				tmp.push_back(sum);
				--j;
			}
			else {
				tmp.push_back(arr[i][j]);
			}
		}
		int size = n - tmp.size();
		while (size--) {
			ins.push_back(0);
		}
		for (int j = tmp.size() - 1; j >= 0; --j) {
			ins.push_back(tmp[j]);
		}
		arr[i] = ins;
	}
	for (int i = 0; i < n; ++i) {
		vector<int> tmp, ins;
		for (int j : arr[i]) {
			if (j == 0) continue;
			tmp.push_back(j);
		}
		int size = n - tmp.size();
		while (size--) {
			ins.push_back(0);
		}
		for (int j : tmp) {
			ins.push_back(j);
		}
		arr[i] = ins;
	}
	return arr;
}

V up(V arr) {
	V temp;
	for (int i = 0; i < n; ++i) {
		vector<int> tmp;
		for (int j = 0; j < n; ++j) {
			if (arr[j][i] == 0) continue;
			tmp.push_back(arr[j][i]);
		}
		while (tmp.size() < n) {
			tmp.push_back(0);
		}
		temp.push_back(tmp);
	}
	for (int i = 0; i < n; ++i) {
		vector<int> tmp;
		for (int j = 0; j < n; ++j) {
			if (temp[i][j] == 0) {
				tmp.push_back(0);
			}
			else if (j < n - 1 && temp[i][j] == temp[i][j + 1]) {
				int sum = temp[i][j] << 1;
				tmp.push_back(sum);
				++j;
			}
			else {
				tmp.push_back(temp[i][j]);
			}
		}
		while (n != tmp.size()) {
			tmp.push_back(0);
		}
		temp[i] = tmp;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			arr[j][i] = temp[i][j];
		}
	}
	return arr;
}

V down(V arr) {
	V temp;
	for (int i = 0; i < n; ++i) {
		vector<int> tmp, ins;
		for (int j = 0; j < n; ++j) {
			if (arr[j][i] == 0) continue;
			tmp.push_back(arr[j][i]);
		}
		int size = n - tmp.size();
		while (size--) {
			ins.push_back(0);
		}
		for (int j : tmp) {
			ins.push_back(j);
		}
		temp.push_back(ins);
	}
	for (int i = 0; i < n; ++i) {
		vector<int> tmp;
		for (int j = n - 1; j >= 0; --j) {
			if (temp[i][j] == 0) {
				tmp.push_back(0);
			}
			else if (j > 0 && temp[i][j] == temp[i][j - 1]) {
				int sum = temp[i][j] << 1;
				tmp.push_back(sum);
				--j;
			}
			else {
				tmp.push_back(temp[i][j]);
			}
		}
		while (n != tmp.size()) {
			tmp.push_back(0);
		}
		temp[i] = tmp;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			arr[j][i] = temp[i][j];
		}
	}
	return arr;
}

void dfs(int cnt, V arr) {
	if (cnt > 5) return;
	getMax(arr);
	dfs(cnt + 1, down(arr));
	dfs(cnt + 1, left(arr));
	dfs(cnt + 1, right(arr));
	dfs(cnt + 1, up(arr));
}

void solution() {
	input();
	dfs(0, a);
	cout << answer;
}

int main() {
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(0);
	solution();
	return 0;
}
