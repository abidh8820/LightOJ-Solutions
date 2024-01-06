#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;

int m, n;
vector<int> S;

LL dp[105][105];

LL call(int pos, int prev) {
    if (pos >= n) return 1;

    LL& ret = dp[pos][prev];
    ret = 0;

    for(int now : S){
        if(abs(now-prev)>2) continue;
        ret += call(pos+1, now);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout <<"Case "<<++cs<<": ";
        cin >> m >> n;

        S.clear();
        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            S.push_back(x);
        }

        memset(dp, -1, sizeof dp);
        LL ans = 0;

        for (int x : S) ans += call(1, x);
        cout << ans <<"\n";
    }
}

