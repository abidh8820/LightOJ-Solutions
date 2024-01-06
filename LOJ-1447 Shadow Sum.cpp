#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";
        int n;
        cin >> n;

        vector<int> v(n);
        for(int i=0; i<n; i++) cin >> v[i];

        LL ans = 0;

        map<int,bool> mp;

        for(int i=n-1; i>=0; i--){
            int val = abs(v[i]);
            if(mp[val]) continue;
            ans += v[i];
            mp[val] = true;
        }

        cout << ans <<"\n";
    }
}

