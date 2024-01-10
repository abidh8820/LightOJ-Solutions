#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1005;
vector<int> g[N];

bool vis[N];
int dp[N][2];

void dfs(int u, int p) {
    dp[u][1] = 1;
    dp[u][0] = 0;

    for (int v : g[u]) {
        if (v == p) continue;
        dfs(v, u);
        dp[u][0] += max(dp[v][1], dp[v][0]);
        dp[u][1] += dp[v][0];
    }
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

        for (int i = 1; i <= n; i++) {
            g[i].clear(), dp[i][0] = dp[i][1] = -1;
        }

        for (int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        LL ans = 0;
        for (int i = 1; i <= n; i++) {
            if (~dp[i][0]) continue;
            dfs(i, i);
            ans += max(dp[i][0], dp[i][1]);
        }

        cout << ans << "\n";
    }
}

