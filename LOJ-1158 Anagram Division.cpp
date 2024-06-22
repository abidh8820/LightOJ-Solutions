#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

LL dp[1025][1001], fac[12];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";

        string s;
        cin >> s;

        int d;
        cin >> d;


        auto f = [&](auto& f, int mask, int rem){
            if(__builtin_popcount(mask) == s.size()) {
                return LL(rem == 0);
            } 

            auto& ret = dp[mask][rem];
            if(~ret) return ret; 


            ret = 0;
            for(int i = 0 ; i < s.size(); i++) {
                if(mask >> i & 1) continue;
                ret += f(f, mask | (1 << i), (rem * 10 + s[i] - '0') % d);
            }
            return ret;
        };


        fac[1] = 1; map<char, int> mp;
        for(int i = 2; i < 11; i++) fac[i] = fac[i - 1] * i;
        for(auto c : s) mp[c]++;


        memset(dp, -1, sizeof dp);
        LL ans =  f(f, 0, 0);
        for(auto[x,y] : mp) ans /= fac[y];
        cout << ans <<"\n";
    }
}

