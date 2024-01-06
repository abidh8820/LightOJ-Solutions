#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 7, K = 20;
vector<int> adj[N];

int anc[N][K];
int level[N];
int val[N];

void dfs(int u, int par) {
    level[u] = level[par] + 1;
    anc[u][0] = par;
    for (int k = 1; k < K; k++) anc[u][k] = anc[anc[u][k - 1]][k - 1];

    for (int v : adj[u]) {
        if (v == par) continue;
        dfs(v, u);
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

int dist(int u, int v) {
    int g = lca(u, v);
    return level[u] + level[v] - 2 * level[g];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        val[1] = 1;
        cout<<"Case "<<++cs<<":\n";
        int n, q;
        cin >> n >> q;

        for(int i=1; i<=n; i++){
            adj[i].clear();
        }

        for (int i = 2; i <= n; i++) {
            int p, v;
            cin >> p >> v;
            p++;
            adj[p].push_back(i);
            val[i] = v;
        }

        dfs(1, 0);

        while (q--) {
            int v, k;
            cin >> v >> k;
            v++;

            int lo = 1, hi = level[v] - 1, res = -1;
            while (lo <= hi) {
                int mid = lo + hi >> 1;
                int u = getanc(v, mid);
                if (val[u] >= k) res = u, lo = mid + 1;
                else hi = mid - 1;
            }
            if(res==-1) res = v;

            cout << res-1<<"\n";
        }
    }
}
