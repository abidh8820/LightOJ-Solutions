#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";
        int n;
        cin >> n;

        vector<int> a(n + 1);

        for (int i = 1; i <= n; i++) cin >> a[i];
        a[0] = 0;

        LL lo = 0, hi = 1e18, ans = 1e18;
        while (lo <= hi) {
            LL mid = lo + hi >> 1;
            LL K = mid;

            bool ok = true;
            for (int i = 1; i <= n; i++) {
                if (a[i] - a[i - 1] > K) {
                    ok = false; break;
                }
                if (a[i] - a[i - 1] == K) K--;
            }

            if (ok) ans = mid, hi = mid - 1;
            else lo = mid + 1;
        }

        cout << ans << "\n";
    }
}

