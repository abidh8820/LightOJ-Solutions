#include <bits/stdc++.h>
using namespace std;

#define int long long 

signed main() {
    int t, c = 0;
    cin >> t;

    while (t--) {
        long long l, p;
        cin >> p >> l;

        set<int> st;
        long long num = p - l;

        vector<int> ans;
        for (int i = 1; i * i <= num; i++) {
            if (num % i) continue;
            if(i>l)  ans.push_back(i);
            if(num/i > l && num/i !=i) ans.push_back(num/i);
        }

        cout << "Case " << ++c << ": ";
        sort(ans.begin(),ans.end());

        if (ans.empty()) cout << "impossible" << endl;

        else {
            for (int i : ans) cout << i << ' ';
            cout << endl;
        }
    }
}

