#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;

const int N = 3e5 + 7;
bool vis[N];

vector<int> adj[N], adjr[N];
vector<int> order, component;

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

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        adj[i].clear(), adjr[i].clear();
    }

    memset(vis, 0, sizeof vis);
    order.clear(), component.clear();

    vector<PII> edges;
    while (m--) {
        int u, v;
        cin >> u >> v;
        edges.emplace_back(u, v);
        adj[u].push_back(v);
        adjr[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs(i);
    }

    memset(vis, 0, sizeof vis);
    reverse(order.begin(), order.end());
    vector<int> ID(n + 1);

    int c = 0;
    for (int i : order) {
        if (!vis[i]) {
            dfs(i, 1);
            c++;
            for (int u : component) ID[u] = c;
            component.clear();
        }
    }

    vector<int> indeg(c + 2), outdeg(c + 2);

    for (auto [u, v] : edges) {
        if (ID[u] == ID[v]) continue;
        indeg[ID[v]]++;
        outdeg[ID[u]]++;
    }

    int in = 0, out = 0;
    for (int i = 1; i <= c; i++) {
        if (indeg[i] == 0) in++;
        if (outdeg[i] == 0) out++;
    }

    if (c == 1) cout << 0 << "\n";
    else cout << max(in, out) << "\n";
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

