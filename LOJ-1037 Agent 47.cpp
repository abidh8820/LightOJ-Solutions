#include "bits/stdc++.h"
using namespace std;

const int N = 17;

int dp[1 << N], health[N];
int grid[N][N], n;

int call(int mask) {
    if (mask == 0) return 0;
    if (dp[mask] != -1) return dp[mask];

    dp[mask] = 1e9;
    for (int j = 0; j < n; j++) {
        if ((mask >> j) & 1) {
            int damage = 1;
            for (int i = 0; i < n; i++) {
                if (((mask >> i) & 1) == 0) damage = max(damage, grid[i][j]);
                dp[mask] = min(dp[mask],(health[j]+damage-1)/damage+call((~(1 << j))&mask));
            }
        }
    }
    return dp[mask];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";
        cin >> n;

        for (int i = 0; i < n; i++) cin >> health[i];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                char ch;
                cin >> ch;
                grid[i][j] = ch - '0';
            }
        }

        memset(dp, -1, sizeof dp);
        cout << call((1 << n) - 1) << endl;
    }
}