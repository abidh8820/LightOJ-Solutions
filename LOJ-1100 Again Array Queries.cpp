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
        cout << "Case " << ++cs << ":\n";
        int n, q;
        cin >> n >> q;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        while (q--) {
            int l, r;
            cin >> l >> r;

            if (r - l + 1 >= 1000) {
                cout << 0 << "\n";
                continue;
            }

            vector<int> now;
            for (int i = l; i <= r; i++) now.push_back(a[i]);
            sort(now.begin(), now.end());

            int ans = 1e9;
            for (int i = 1; i <= r - l; i++)
                ans = min(ans, now[i] - now[i - 1]);
            cout << ans << "\n";
        }
    }
}

