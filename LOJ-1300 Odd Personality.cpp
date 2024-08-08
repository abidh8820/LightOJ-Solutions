#include <bits/stdc++.h>
using namespace std;
 
using LL = long long;
using PII = pair<int, int>;
 
const int N = 1e5 + 7;
int dt[N], low[N], Time;
vector<int> adj[N];

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
    void merge(int u, int v) { 
        if(find(u) == find(v)) return;
        par[find(u)] = find(v);
    }
};


void findBridges(int u, int p, map<PII, bool>& bad) {
    low[u] = dt[u] = ++Time;
    for (auto v : adj[u]) {
        if (v == p) continue;
        if (dt[v]) low[u] = min(low[u], dt[v]);
        else {
            findBridges(v, u, bad);
            if (dt[u] < low[v]) bad[PII(u,v)] = bad[PII(v, u)] = true;
            low[u] = min(low[u], low[v]);
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;
    while(t--){
        cout <<"Case "<<++cs<<": ";

        int n, m;
        cin >> n >> m;

        for(int i = 0; i < n; i++) adj[i].clear(), dt[i] = 0;
        map<PII, bool> bad;

        vector<PII> edges;
        for(int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            edges.emplace_back(u, v);
        }
        
        Time = 0;
        for(int i = 0; i < n; i++) 
            if(dt[i] == 0) findBridges(i, -1, bad);
        DSU dsu(n * 3);

        for(auto[u,v] : edges){
            if(bad[PII(u,v)]) continue;
            dsu.merge(u, v + n);
            dsu.merge(u + n, v);
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans += dsu.find(i) == dsu.find(i + n);
        }

        cout << ans <<"\n";
    }

}
