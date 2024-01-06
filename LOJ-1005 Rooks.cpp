#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, c = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++c << ": ";
        int n, k;
        cin >> n >> k;

        if (k > n) {
            cout << 0 << endl;
            continue;
        }

        long long fac = 1;
        for (int i = 1; i <= k; i++) fac *= i;
        long long ans = 1;

        for (int i = 0; i < k; i++) {
            ans *= (n - i) * (n - i);
            long long g = gcd(ans, fac);
            ans /= g, fac /= g;
        }
        cout << ans / fac << endl;
    }
}

