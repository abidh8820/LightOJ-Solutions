#include "bits/stdc++.h"
using namespace std;

typedef long long LL;
const LL N = 1e6 + 7;

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
        adj[i].clear();
        adjr[i].clear();
        vis[i] = false;
    }
    order.clear();

    vector<pair<int, int>> edges;
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adjr[v].push_back(u);
        edges.emplace_back(u, v);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs(i);
    }

    memset(vis, 0, sizeof vis);
    reverse(order.begin(), order.end());

    map<int, int> ID;
    int cnt = 0;
    for (int i : order) {
        if (!vis[i]) {
            component.clear();
            dfs(i, 1), cnt++;
            for (int x : component) ID[x] = cnt;
        }
    }

    map<int, int> in, out;
    for (auto [u, v] : edges) {
        if (ID[u] != ID[v]) {
            in[ID[v]]++;
            out[ID[u]]++;
        }
    }

    int ans = 0;
    for (int i = 1; i <= cnt; i++) {
        ans += (in[i] == 0);
    }

    cout << ans << "\n";
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

