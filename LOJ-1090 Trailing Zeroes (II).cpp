#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;
const int N = 1e6 + 7;

int main() {
    int t, cs = 0;

    cin >> t;
    while (t--) {
        cout << "Case " << ++cs << ": ";
        int n, r, p, q;
        cin >> n >> r >> p >> q;

        int up5 = 0, up2 = 0;
        int d5 = 0, d2 = 0;

        int cur = 2;
        while (cur < N) {
            up2 += n / cur;
            d2 += r / cur + (n - r) / cur;
            cur *= 2;
        }

        cur = 5;
        while (cur < N) {
            up5 += n / cur;
            d5 += r / cur + (n - r) / cur;
            cur *= 5;
        }

        int cnt5 = 0, cnt2 = 0;
        while (p % 5 == 0) cnt5++, p /= 5;
        while (p % 2 == 0) cnt2++, p /= 2;

        cnt5 *= q, cnt2 *= q;
        up2 += cnt2, up5 += cnt5;
        up2 -= d2, up5 -= d5;

        cout << min(up2, up5) << "\n";
    }
}

