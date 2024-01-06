#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 1e6 + 7;
const int M = 1e9 + 7;

LL BM(LL a, LL p) {
    if (p == 0) return 1;
    if (p == 1) return a;
    if (p & 1) return (a * BM(a, p - 1)) % M;
    LL f = BM(a, p / 2);
    return (f * f) % M;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";
        LL n, m;
        cin >> n >> m;

        unordered_map<LL, LL> mp;
        while (n % 2 == 0) n /= 2, mp[2]++;
        for (LL i = 3; i * i <= n; i += 2) {
            if (n % i) continue;
            while (n % i == 0) n /= i, mp[i]++;
        }
        if (n > 1) mp[n]++;

        LL ans = 1;
        for (auto [x, y] : mp) {
            LL p = y * m;
            ans = (ans * (BM(x, p + 1) - 1 + M)) % M;
            ans = (ans * BM(x - 1, M - 2)) % M;
        }
        cout << ans << endl;;
    }
}

