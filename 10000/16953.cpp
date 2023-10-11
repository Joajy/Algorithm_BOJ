#include <iostream>
using namespace std;

int main()
{
    int a, b, ans = 0;
    cin >> a >> b;
    while(b > 0){
        if(a > b){
            cout << -1;
            return 0;
        }
        if(a == b){
            cout << ans + 1;
            return 0;
        }
        if(b % 10 == 1) b /= 10;
        else if(b % 2 == 0) b >>= 1;
        else{
            cout << -1;
            return 0;
        }
        ++ans;
    }
    return 0;
}
