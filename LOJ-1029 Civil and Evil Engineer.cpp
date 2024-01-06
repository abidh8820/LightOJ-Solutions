#include <bits/stdc++.h>
using namespace std;

using LL = long long;

struct DSU {
    vector<int> par;
    DSU() {}

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
        int n;
        cin >> n;

        vector<tuple<int, int, int>> edges;
        while (true) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            edges.emplace_back(w, u, v);
            if (!u && !v && !w) break;
        }

        DSU mx(n), mn(n);

        LL max_ans = 0, min_ans = 0;

        sort(edges.begin(), edges.end());
        for (auto [w, u, v] : edges) {
            if (mn.find(u) == mn.find(v)) continue;
            min_ans += w, mn.merge(u, v);
        }

        sort(edges.rbegin(), edges.rend());
        for (auto [w, u, v] : edges) {
            if (mx.find(u) == mx.find(v)) continue;
            max_ans += w, mx.merge(u, v);
        }

        LL ans = min_ans + max_ans;
        if (ans % 2 == 0) printf("Case %d: %lld\n", ++cs, ans / 2);
        else printf("Case %d: %lld/2\n", ++cs, ans);
    }
}

