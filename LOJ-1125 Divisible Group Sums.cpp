#include "bits/stdc++.h"
using namespace std;

typedef long long LL;
LL dp[202][22][22], a[202];
LL d, m, n, q;

LL call( LL idx, LL taken, LL mod) {
    if (taken == m) return (mod == 0);
    if (idx > n) return 0;

    auto& ret = dp[idx][taken][mod];
    if (ret != -1) return ret;

    ret = call(idx + 1, taken, mod);
    ret += call(idx + 1, taken + 1, (((mod + a[idx]) % d) + d) % d);
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ":" << endl;

        cin >> n >> q;
        for (int i = 1; i <= n; i++) cin >> a[i];

        while (q--) {
            memset(dp, -1, sizeof dp);
            cin >> d >> m;
            cout << call(1, 0, 0) << endl;;
        }
    }
}

