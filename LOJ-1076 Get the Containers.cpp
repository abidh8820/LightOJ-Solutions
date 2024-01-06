#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;

int main() {
    int t, cs = 0;

    cin >> t;
    while (t--) {
        cout << "Case " << ++cs << ": ";
        int n, m;
        cin >> n >> m;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int lo = 0, hi = 1e9, ans = -1;

        while (lo <= hi) {
            int mid = lo + hi >> 1;
            LL cnt = 1, sum = 0;

            for (int i = n - 1; i >= 0; i--) {
                if (a[i] > mid) {
                    cnt = 1e9;
                    continue;
                }

                if (sum + a[i] <= mid) sum += a[i];
                else sum = a[i], cnt++;
            }

            if (cnt <= m) {
                ans = mid, hi = mid - 1;
            } else lo = mid + 1;
        }

        cout << ans << "\n";
    }
}

