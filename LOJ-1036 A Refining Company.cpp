#include "bits/stdc++.h"
using namespace std;

const int N = 500 + 7;
typedef long long LL;

LL U[N][N], R[N][N], dp[N][N][2];
LL Up[N][N], Left[N][N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";

        int n, m;
        cin >> n >> m;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> U[i][j];
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> R[i][j];
            }
        }

        memset(dp, 0, sizeof dp);

        for (int i = 1; i <= m; i++) {
            dp[1][i][0] = R[1][i];
            dp[i][1][1] = U[i][1];
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                Left[i][j] = U[i][j];
                Left[i][j] += Left[i][j - 1];
            }
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                Up[j][i] = R[j][i];
                Up[j][i] += Up[j - 1][i];
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j][0] = max(dp[i][j - 1][0], dp[i][j - 1][1]) + Up[i][j];
                dp[i][j][1] = max(dp[i - 1][j][0], dp[i - 1][j][1]) + Left[i][j];
            }
        }

        cout << max(dp[n][m][0], dp[n][m][1]) << endl;
    }
}

