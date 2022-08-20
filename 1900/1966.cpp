#include<iostream>
#include<queue>
#include<algorithm>
#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
using namespace std;
int main()
{
    fast;
    int t, n, m;
    int ar[101];        //to choose the largest number of updated queue
    cin >> t;
    while (t--) {
        int ans = 0;
        queue<pair<int, int>> q;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> ar[i];
            q.push({ ar[i], i });
        }
        sort(ar, ar + n);
        int max_num = ar[n - 1];
        while (1) {
            pair<int, int> cur = q.front();
            if (max_num == cur.first && cur.second == m)
                break;
            //if cur is maximum, printed(in this senario) and pop & count plus
            if (cur.first == max_num) {
                max_num = ar[--n - 1];
                ans++;
                q.pop();
            }
            //if not, pass over this front num of queue
            else if (cur.first < max_num) {
                q.pop();
                q.push(cur);
            }
        }
        cout << ans + 1 << '\n';
    }
    return 0;
}
