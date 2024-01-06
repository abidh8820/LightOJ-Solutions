#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 7;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";

        int n, m;
        cin >> n >> m;

        vector<int> dp(N);
        vector<int> a(n), c(n);
        vector<int> cnt(N);

        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> c[i];

        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            cnt.assign(N, 0);
            for (int sum = 1; sum < N; sum++) {
                if (dp[sum]) continue;
                int prev = sum - a[i];
                if (prev < 0) continue;
                if (cnt[prev] >= c[i]) continue;
                dp[sum] |= dp[prev];
                cnt[sum] = cnt[prev] + 1;
            }
        }

        LL ans = 0;
        for (int i = 1; i <= m; i++) ans += dp[i];
        cout << ans << "\n";
    }
}

