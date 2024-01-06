#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 17;
int n, cost[20][20], dp[17][N];

int calc(int id, int mask) {
    if (id >= n) return 0;
    if (dp[id][mask] != -1)return dp[id][mask];
    int &ret = dp[id][mask] = 0;
    for (int i = 0; i < n; i++) {
        if (((1 << i) & mask)) continue;
        ret = max(ret, cost[id][i] + calc(id + 1, (mask | (1 << i))));
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, c = 0;
    cin >> t;

    while (t--) {
        cin >> n;
        memset(dp, -1, sizeof dp);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> cost[i][j];
            }
        }

        cout << "Case " << ++c << ": ";
        cout << calc(0, 0) << endl;
    }
}