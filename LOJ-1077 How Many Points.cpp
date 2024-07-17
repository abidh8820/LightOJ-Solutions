#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;

int main() {
    int t, cs = 0;

    cin >> t;
    while (t--) {
        cout << "Case " << ++cs << ": ";

        LL x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        LL ans = gcd(abs(x1 - x2), abs(y1 - y2)) + 1;
        cout << ans << endl;
    }
}

