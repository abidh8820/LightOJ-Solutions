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

        int dp[n][2];
        memset(dp, 0x01, sizeof dp);

        vector<int> a(n), b(n);

        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        vector<int> x(n - 1), y(n - 1);
        for (int i = 0; i < n - 1; i++) cin >> x[i];
        for (int i = 0; i < n - 1; i++) cin >> y[i];

        dp[0][0] = a[0];
        dp[0][1] = b[0];

        for (int i = 1; i < n; i++) {
            dp[i][0] = min(dp[i][0], dp[i - 1][0] + a[i]);
            dp[i][0] = min(dp[i][0], dp[i - 1][1] + a[i] + y[i - 1]);
            dp[i][1] = min(dp[i][1], dp[i - 1][1] + b[i]);
            dp[i][1] = min(dp[i][1], dp[i - 1][0] + b[i] + x[i - 1]);
        }

        cout << min(dp[n - 1][0], dp[n - 1][1]) << "\n";
    }
}

