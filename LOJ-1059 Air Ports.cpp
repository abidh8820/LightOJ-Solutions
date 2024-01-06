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
        cout << "Case " << ++cs << ": ";
        int n, m, a;
        cin >> n >> m >> a;

        vector<tuple<int, int, int>> edges(m);

        for (auto& [w, u, v] : edges) {
            cin >> u >> v >> w;
        }
        sort(edges.begin(), edges.end());

        DSU dsu(n);
        LL cost = 0;

        for (auto [w, u, v] : edges) {
            if (w >= a) continue;
            if (dsu.find(u) != dsu.find(v)) dsu.merge(u, v), cost += w;
        }

        int cnt = 0;
        for (int i = 1; i <= n; i++) cnt += (dsu.find(i) == i);

        cost += 1LL * cnt * a;

        cout << cost << " " << cnt << "\n";
    }
}

