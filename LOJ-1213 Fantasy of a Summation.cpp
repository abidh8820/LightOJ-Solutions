#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;

LL n, k, M;
LL bigMod(LL a, LL e) {
    if (e == -1) e = M - 2;
    LL ret = 1;
    while (e) {
        if (e & 1) ret = ret * a % M;
        a = a * a % M, e >>= 1;
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";
        cin >> n >> k >> M;

        LL ans = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            ans += x;
        }
        ans %= M;

        ans *= bigMod(n, k - 1) * k %M;
        ans %= M;
        cout << ans << "\n";
    }
}

