#include <bits/stdc++.h>
using namespace std;

#define int long long 

signed main() {
    int t, c = 0;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int sum  = 0;
        for(int i=0; i<n; i++) {
            int x; cin >> x;
            if(x>=0) sum += x;
        }
        cout << "Case " << ++c << ": "<<sum<<endl;
    }
}

