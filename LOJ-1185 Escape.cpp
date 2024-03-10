#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e6 + 7;
vector<int> g[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t, cs = 0;
  cin >> t;

  while (t--) {
    cout << "Case " << ++cs << ": ";
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= 2 * n; i++) g[i].clear();
    for (int i = 1; i <= m; i++) {
      int u, v;
      cin >> u >> v;
      g[u].push_back(v + n);
      g[u + n].push_back(v);
      g[v].push_back(u + n);
      g[v + n].push_back(u);
    }

    vector<int> Q, vis(2 * n + 2, 0);
    for (int x : g[1 + n]) Q.push_back(x), vis[x] = true;

    for (int i = 0; i < Q.size(); i++) {
      int u = Q[i];
      for (int v : g[u]) {
        if (vis[v]) continue;
        Q.push_back(v);
        vis[v] = true;
      }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
      ans += vis[i + n];
    }

    cout << ans << "\n";
  }
}

