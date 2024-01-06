#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;

const int N = 15;
const int INF = 1e9 + 7;

int cost[N][N], n;
int dp[1 << N];

int call(int mask) {
    if (__builtin_popcount(mask) == n) return 0;
    int& ret = dp[mask];

    if (~ret) return ret;
    ret = INF;

    for (int i = 0; i < n; i++) {
        if (mask >> i & 1) continue;
        int now = cost[i][i];
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (mask >> j & 1) now += cost[i][j];
        }
        ret = min(ret, call(mask | (1 << i)) + now);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";
        cin >> n;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> cost[i][j];
            }
        }

        memset(dp, -1, sizeof dp);
        cout << call(0) << "\n";
    }
}

