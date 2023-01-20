#include<iostream>
#include<queue>
#include<functional>
#include<vector>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n, num;
	cin >> n;
	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;
	for (int i = 1; i <= n; i++) {
		cin >> num;
		if (maxHeap.size() == minHeap.size())
			maxHeap.push(num);
		else
			minHeap.push(num);
		if (!maxHeap.empty() && !minHeap.empty() && maxHeap.top() > minHeap.top()) {
			int maxVal = maxHeap.top(); maxHeap.pop();
			int minVal = minHeap.top(); minHeap.pop();
			maxHeap.push(minVal);
			minHeap.push(maxVal);
		}
		cout << maxHeap.top() << '\n';
	}
	return 0;
}
