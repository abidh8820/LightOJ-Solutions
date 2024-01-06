#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;

const int N = 18;
const int INF = 1e7 + 7;

int W[N][N];
int deg[N];

vector<int> odds;
int dp[1<<N];


int call(int mask) {
    if (__builtin_popcount(mask) == odds.size()) return 0;
    int& ret = dp[mask];
    if (~ret) return ret;

    ret = INF;

    for (int i = 0; i < odds.size(); i++) {
        for (int j = 0; j < odds.size(); j++) {
            if (i == j) continue;
            int u = odds[i], v = odds[j];
            if (mask >> u & 1) continue;
            if (mask >> v & 1) continue;
            ret = min(ret, W[u][v] + call(mask | (1 << u) | (1 << v)));
        }
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

        int n, m;
        cin >> n >> m;

        LL ans = 0;

        memset(W, 0x0b, sizeof W);
        memset(deg, 0, sizeof deg);
        memset(dp, -1, sizeof dp);

        for (int i = 1; i <= m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            W[u][v] = W[v][u] = min(w, W[u][v]);
            deg[u]++, deg[v]++;
            ans += w;
        }

        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    W[i][j] = min({W[i][j], W[i][k] + W[k][j]});
                }
            }
        }

        odds.clear();
        for (int i = 1; i <= n; i++) {
            if (deg[i] & 1) odds.push_back(i);
        }

        assert(odds.size() % 2 == 0);
        cout << ans + call(0) << "\n";
    }
}

