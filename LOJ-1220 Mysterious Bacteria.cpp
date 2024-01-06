#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> PII;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    LL t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";
        LL n;
        cin >> n;

        bool neg = false;
        if (n < 0) {
            neg = true;
            n = -n;
        }

        map<LL, LL> mp;
        for (LL p = 2; p * p <= n; p++) {
            while (n % p == 0) mp[p]++, n /= p;
        }
        if (n > 1) mp[n]++;

        LL g = 0;
        for (auto [x, y] : mp) g = gcd(g, y);
        while (neg && g % 2 == 0) g /= 2;

        cout << g << "\n";
    }
}

