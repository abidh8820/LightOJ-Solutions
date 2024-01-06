#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1005;

int dp[N][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        memset(dp, 254, sizeof dp);

        dp[0][1] = a[0];

        int ans = a[0];
        for (int i = 1; i < n - 1; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = (dp[i - 1][0] + a[i]);

            if (i - 2 >= 0) dp[i][1] = max(dp[i][1], dp[i - 2][1] + a[i]);
            ans = max(ans, dp[i][0]);
            ans = max(ans, dp[i][1]);
        }

        memset(dp, 254, sizeof dp);
        dp[0][0] = 0;

        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = (dp[i - 1][0] + a[i]);
            if (i - 2 >= 0) dp[i][1] = max(dp[i][1], dp[i - 2][1] + a[i]);
            if (i - 2 >= 0) dp[i][1] = max(dp[i][1], dp[i - 2][0] + a[i]);
            ans = max(ans, dp[i][0]);
            ans = max(ans, dp[i][1]);
        }
        cout << ans << "\n";
    }
}

