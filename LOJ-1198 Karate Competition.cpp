#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;

const int N = 105;
int a[N], b[N];

int dp[N][N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";

        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> b[i];

        sort(a + 1, a + 1 + n);
        sort(b + 1, b + 1 + n);

        memset(dp, 0, sizeof dp);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (a[i] > b[j]) dp[i][j] = dp[i - 1][j - 1] + 2;
                if (a[i] < b[j]) dp[i][j] = dp[i][j - 1];
                if (a[i] == b[j]) dp[i][j] = max(dp[i - 1][j - 1] + 1, dp[i][j - 1]);
            }
        }

        cout << dp[n][n] << "\n";
    }
}

