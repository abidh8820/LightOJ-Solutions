#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> PII;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cnt = 0;
    LL t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";

        LL n;
        cin >> n;

        if (n <= 2) {
            cout << 0 << "\n";
            continue;
        }

        LL sum = 0, cur = n;
        sum -= n + n * (n + 1) / 2;

        int sq = sqrt(n);
        for (int i = 1; i <= sq; i++) {
            sum += (n / i) * i;
        }

        for (int i = 1; i <= sq; i++) {
            LL l = n / (i + 1) + 1, r = n / i;
            l = max(l, 1LL * sq + 1);
            sum += max(0LL, (r * (r + 1) / 2 - l * (l - 1) / 2) * i);
        }

        assert(1LL * cnt * cnt <= 4 * n);
        cout << sum + 1 << "\n";
    }
}

