#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

map<LL, int> factorize(LL x) {
    map<LL, int> ret;
    for (LL i = 2; i * i <= x; i++) {
        if (x % i) continue;
        while (x % i == 0) ret[i]++, x /= i;
    }
    if (x > 1) ret[x]++;
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";
        LL a, b, L;
        cin >> a >> b >> L;

        auto mp1 = factorize(lcm(a, b));
        auto mp2 = factorize(L);
        map<LL,int> mp3;

        for (auto [x, y] : mp2) {
            if (mp1[x] < y) mp3[x] = y;
        }

        LL ans = 1;
        for (auto [x, y] : mp3) {
            for (int k = 0; k < y; k++) ans *= x;
        }

        if (lcm(ans, lcm(a, b)) == L) cout << ans << "\n";
        else cout << "impossible\n";
    }
}

