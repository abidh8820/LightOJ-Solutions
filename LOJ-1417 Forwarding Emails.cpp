#include "bits/stdc++.h"
using namespace std;

using LL = long long;
using PII = pair<int, int>;
const LL N = 5e4 + 7;

bool vis[N];
int sz[N];
vector<int> adj[N], adjr[N], g[N];
// g is the condensed graph

vector<int> order, component, comp[N];
vector<PII> edges;

// tp = 0 ,finding topo order
// tp = 1 , reverse edge traversal

void dfs(int u, int tp = 0) {
  vis[u] = true;
  if (tp) component.push_back(u);
  auto& ad = (tp ? adjr : adj);
  for (int v : ad[u])
    if (!vis[v]) dfs(v, tp);
  if (!tp) order.push_back(u);
}

int dp[N];
int call(int u) {
  if (~dp[u]) return dp[u];
  dp[u] = sz[u];
  for (int v : g[u]) dp[u] += call(v);
  return dp[u];
}

void solve() {
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    adj[i].clear(), adjr[i].clear(), comp[i].clear();
    g[i].clear(), vis[i] = false, sz[i] = 0;
  }
  order.clear(), component.clear(), edges.clear();

  for (int i = 1; i <= n; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adjr[v].push_back(u);
    edges.emplace_back(u, v);
  }

  for (int i = 1; i <= n; i++) if (!vis[i]) dfs(i);
  for (int i = 0; i <= n; i++) vis[i] = 0;
  reverse(order.begin(), order.end());
  vector<LL> ID(n + 1);

  LL ptr = 0;
  for (LL i : order) {
    if (vis[i]) continue;
    dfs(i, 1), ptr++;
    for (LL u : component) ID[u] = ptr;
    sz[ptr] = component.size();
    comp[ptr] = component, component.clear();
  }

  for (auto [u, v] : edges) {
    if (ID[u] == ID[v]) continue;
    g[ID[u]].push_back(ID[v]);
  }

  int best = 0, mx = 0;
  for (int i = 1; i <= ptr; i++) dp[i] = -1;
  for (int i = 1; i <= ptr; i++) {
    if (call(i) > mx) {
      mx = call(i), best = i;
    }
  }

  vector<int> cand;
  for (int i = 1; i <= ptr; i++) {
    if (call(i) == mx) {
      for (int x : comp[i]) cand.push_back(x);
    }
  }

  sort(cand.begin(), cand.end());
  cout << cand[0] << "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, cs = 0;
  cin >> t;

  while (t--) {
    cout << "Case " << ++cs << ": ";
    solve();
  }
}

