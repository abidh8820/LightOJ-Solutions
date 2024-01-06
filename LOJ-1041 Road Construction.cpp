#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;

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
    int t, cs = 0;

    cin >> t;
    while (t--) {
        cout << "Case " << ++cs << ": ";

        map<string, int> ID;
        int cnt = 0, m;
        cin >> m;

        vector<tuple<int, int, int>> edges(m);
        for (int i = 0; i < m; i++) {
            string u, v;
            int w;
            cin >> u >> v >> w;
            if (!ID.count(u)) ID[u] = ++cnt;
            if (!ID.count(v)) ID[v] = ++cnt;
            edges[i] = {w, ID[u], ID[v]};
        }

        DSU dsu(cnt);
        sort(edges.begin(), edges.end());

        LL ans = 0;
        for (auto [w, u, v] : edges) {
            if (dsu.find(u) == dsu.find(v)) continue;
            ans += w, dsu.merge(u, v);
        }

        set<int> st;
        for (int i = 1; i <= cnt; i++) {
            st.insert(dsu.find(i));
        }

        if (st.size() == 1) cout << ans << "\n";
        else cout << "Impossible\n";
    }
}

