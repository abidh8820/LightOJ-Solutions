#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 7;

struct DSU {
    vector<int> par;

    DSU(){};

    DSU(int n) {
        par.resize(n + 2);
        iota(par.begin(), par.end(), 0);
    }

    int find(int u) {
        if (u == par[u]) return u;
        return par[u] = find(par[u]);
    }
    void merge(int u, int v) { par[find(u)] = find(v); }
};


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ":\n";
        int n, m;
        cin >> n >> m;

        vector<tuple<int, int, int>> edges;
        for (int i = 1; i <= m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.emplace_back(w, u, v);

            sort(edges.begin(), edges.end());
            DSU dsu(n);
            LL ans = 0;

            vector<tuple<int, int, int>> taken;
            for (auto [W, U, V] : edges) {
                if (dsu.find(U) == dsu.find(V)) continue;
                ans += W, dsu.merge(U, V);
                taken.emplace_back(W, U, V);
            }

            edges = taken;

            int cnt = 0;
            for (int i = 1; i <= n; i++) cnt += (dsu.find(i) == i);
            if (cnt != 1 or ans > 1e8) ans = -1;
            cout << ans << "\n";
        }
    }
}

