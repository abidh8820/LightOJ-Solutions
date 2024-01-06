#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;

const int INF = 1e7 + 7;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";
        int n, k;
        cin >> n >> k;

        vector<int> a(n), dp(n + 1, INF);
        for (int i = 0; i < n; i++) cin >> a[i];

        sort(a.begin(), a.end());
        dp[n] = 0;

        for (int i = n - 1; i >= 0; i--) {
            auto it = upper_bound(a.begin(), a.end(), a[i] + 2 * k);
            int x = it - a.begin();
            if (x - i >= 3) dp[i] = min(dp[i], dp[x] + 1);
            if (x - i >= 4) dp[i] = min(dp[i], dp[x - 1] + 1);
            if (x - i >= 5) dp[i] = min(dp[i], dp[x - 2] + 1);
        }


        if (dp[0] >= INF) dp[0] = -1;
        cout << dp[0] << "\n";
    }
}

