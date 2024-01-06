#include <bits/stdc++.h>
using namespace std;

using PII = pair<int, int>;
const int N = 3e5 + 7, K = 20;
vector<PII> adj[N];

int anc[N][K];
int Min[N][K];
int Max[N][K];
int level[N];

void dfs(int u, int par, int val) {
    level[u] = level[par] + 1;
    anc[u][0] = par;
    Min[u][0] = val;
    Max[u][0] = val;

    for (int k = 1; k < K; k++) anc[u][k] = anc[anc[u][k - 1]][k - 1];
    for (int k = 1; k < K; k++)
        Min[u][k] = min(Min[anc[u][k - 1]][k - 1], Min[u][k - 1]);
    for (int k = 1; k < K; k++)
        Max[u][k] = max(Max[anc[u][k - 1]][k - 1], Max[u][k - 1]);

    for (auto [v,w] : adj[u]) {
        if (v == par) continue;
        dfs(v, u, w);
    }
}

int lca(int u, int v) {
    if (level[u] > level[v]) swap(u, v);
    for (int k = K - 1; k >= 0; k--)
        if (level[u] + (1 << k) <= level[v]) v = anc[v][k];

    if (u == v) return u;
    for (int k = K - 1; k >= 0; k--)
        if (anc[u][k] != anc[v][k]) u = anc[u][k], v = anc[v][k];
    return anc[u][0];
}

int getanc(int u, int d) {
    for (int k = 0; k < K; k++)
        if (d & (1 << k)) u = anc[u][k];
    return u;
}

int getmax(int u, int d) {
    int mx = 0;
    for (int k = 0; k < K; k++) {
        if (d & (1 << k)) mx = max(mx, Max[u][k]), u = anc[u][k];
    }
    return mx;
}

int getmin(int u, int d) {
    int mn = 1e9;
    for (int k = 0; k < K; k++) {
        if (d & (1 << k)) mn = min(mn, Min[u][k]), u = anc[u][k];
    }
    return mn;
}

void getans(int u, int v) {
    int mn = 1e9, mx = 0;
    int g = lca(u, v);
    if (u != g) {
        mn = min(getmin(u, level[u] - level[g]), mn);
        mx = max(getmax(u, level[u] - level[g]), mx);
    }
    if (v != g) {
        mn = min(getmin(v, level[v] - level[g]), mn);
        mx = max(getmax(v, level[v] - level[g]), mx);
    }
    cout << mn << " " << mx << "\n";
}

int dist(int u, int v) {
    int g = lca(u, v);
    return level[u] + level[v] - 2 * level[g];
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for (int cs = 1; cs <= t; cs++) {
        cout << "Case " << cs << ":\n";

        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) adj[i].clear();

        for (int i = 1; i < n; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }

        dfs(1, 0, 0);

        int q;
        cin >> q;

        while (q--) {
            int u, v;
            cin >> u >> v;
            getans(u, v);
        }
    }
}
