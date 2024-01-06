#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, c = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++c << ": ";
        long long n;    cin >> n;

        if(n==1 ) {
            cout<<"1 1"<<endl;  continue;
        }

        long long lo = 1, hi = 1e8, sum, cur, cnt;
        while (lo <= hi) {
            long long mid = (lo + hi) / 2;
            if (mid * mid < n) {
                sum = mid * mid, cnt = mid;
                cur = 2 * mid + 1, lo = mid + 1;
            } 
            else  hi = mid - 1;
        }

        if (cnt % 2 == 0) {
            int rest = n - sum;
            if (rest <= cur / 2)  cout << cnt + 1 << ' ' << rest << endl;
            else if (rest == (cur / 2 + 1))   cout << cnt + 1 << ' ' << cnt + 1 << endl;
            else  cout << (cnt + 1) - (n - (sum + (cur / 2 + 1))) << ' '  << cnt + 1 << endl;
        } 

        else {
            int rest = n - sum;
            if (rest <= cur / 2)    cout << rest << ' ' << cnt + 1 << endl;
            else if (rest == (cur / 2 + 1))  cout << cnt + 1 << ' ' << cnt + 1 << endl;
            else cout << cnt+1<<' '<<(cnt + 1) - (n - (sum + (cur / 2 + 1))) <<  endl;
        }
    }
}