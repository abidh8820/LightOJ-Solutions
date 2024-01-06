#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "dbg.h"
#else
#define dbg(...)
#endif

typedef long long LL;
typedef pair<LL, LL> PII;

const LL N = 1e6 + 7;
vector<PII> adj[N];
vector<LL> mx[N];
LL dp[N], all[N];

void dfs(LL u, LL p) {
  dp[u] = 0;
  for (auto [v, w] : adj[u]) {
    if (v == p) continue;
    dfs(v, u);
    dp[u] = max(dp[u], dp[v] + w);
  }
}

void dfs2(LL u, LL p, LL dis) {
  all[u] = dis;
  LL m = adj[u].size();
  mx[u].resize(m);

  for (LL i = m - 1; i >= 0; i--) {
    auto [v, w] = adj[u][i];
    if (v != p) mx[u][i] = dp[v] + w;
    if (i + 1 < m) mx[u][i] = max(mx[u][i], mx[u][i + 1]);
  }

  LL pref = dis;
  for (LL i = 0; i < m; i++) {
    auto [v, w] = adj[u][i];
    if (v == p) continue;
    LL nxt = pref;

    if (i + 1 < m) nxt = max(nxt, mx[u][i + 1]);
    dfs2(v, u, nxt + w);
    pref = max(pref, dp[v] + w);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  LL t, cs = 0;
  cin >> t;

  while (t--) {
    cout << "Case " << ++cs << ":\n";
    LL n;
    cin >> n;

    
    for (LL i = 1; i <= n; i++) adj[i].clear(), dp[i] = all[i] = 0, mx[i].clear();
    for (LL i = 1; i < n; i++) {
      LL u, v, w;
      cin >> u >> v >> w;
      u++, v++;
      adj[u].emplace_back(v, w);
      adj[v].emplace_back(u, w);
    }

    dfs(1, 0);
    dfs2(1, 0, 0);

    for (LL i = 1; i <= n; i++) cout << max(all[i], dp[i]) << "\n";
  }
}

