#include "bits/stdc++.h"
using namespace std;

const int N = 1e6 + 7;
int a[N][3], dp[N][3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";

        int n;
        cin >> n;

        cin >> a[0][0] >> a[0][1] >> a[0][2];
        dp[0][0] = a[0][0];
        dp[0][1] = a[0][1];
        dp[0][2] = a[0][2];

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 3; j++) cin >> a[i][j];

            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + a[i][0];
            dp[i][1] = min(dp[i - 1][2], dp[i - 1][0]) + a[i][1];
            dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]) + a[i][2];
        }
        cout << min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]}) << endl;
    }
}