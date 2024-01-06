#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;

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

        int n;
        cin >> n;

        vector<tuple<int, int, int>> edges;

        LL total_cost = 0;
        for (int u = 1; u <= n; u++) {
            for (int v = 1; v <= n; v++) {
                int w; cin >> w;
                if (w == 0) continue;

                edges.emplace_back(w, u, v);
                total_cost += w;
            }
        }

        sort(edges.begin(), edges.end());
        DSU dsu(n);

        LL used = 0;
        for (auto [w, u, v] : edges) {
            if (dsu.find(u) == dsu.find(v)) continue;
            used += w, dsu.merge(u, v);
        }

        set<int> st;
        for (int i = 1; i <= n; i++) st.insert(dsu.find(i));

        if (st.size() != 1) {
            cout << -1 << "\n";
            continue;
        }
        cout << total_cost - used << "\n";
    }
}

