#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        long long dp[300][300];
        long long a[300][300];
        memset(dp, 0, sizeof dp);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                cin >> a[i][j];
                if (j == 1) {
                    dp[i][j] = dp[i - 1][j] + a[i][j];
                } else {
                    dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + a[i][j];
                }
            }
        }

        for (int i = n - 1; i >= 1; i--) {
            for (int j = 1; j <= i; j++) {
                int id = 2 * n - i;
                cin >> a[id][j];
                dp[id][j] = max(dp[id - 1][j], dp[id - 1][j + 1]) + a[id][j];
            }
        }
        cout<<"Case "<<++cs<<": ";
        cout << dp[2 * n - 1][1] << endl;
    }
}

