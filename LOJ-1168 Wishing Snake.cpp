#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int,int>;
const LL N = 1e4 + 7;

bool vis[N];

vector<int> adj[N], adjr[N], g[N];
//g is the condensed graph

vector<int> order, component;
vector<PII> edges;

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

    for(int i = 0; i <= 1000; i++) {
        adj[i].clear();
        adjr[i].clear();
        g[i].clear();
        order.clear();
        component.clear();
        edges.clear();
        vis[i] = false;
    }

    int n;
    cin >> n;

    set<int> nodes;

    for(int k = 0; k < n; k++) {
        int m;
        cin >> m;

        while(m--) {
            int u, v;
            cin >> u >> v;
            nodes.insert(u);
            nodes.insert(v);
            adj[u].push_back(v);
            adjr[v].push_back(u);
            edges.emplace_back(u, v);
        }
    }

    for (int i : nodes) {
        if (!vis[i]) dfs(i);
    }

    memset(vis, 0, sizeof vis);
    reverse(order.begin(), order.end());


    map<int,int> ID;
    LL ptr = 0;
    for (LL i : order) {
        if (!vis[i]) {
            dfs(i, 1);
            ptr++;
            for (LL u : component) ID[u] = ptr;
            component.clear();
        }
    }

    vector<int> inDeg(ptr + 1), outDeg(ptr + 1);
    for (auto [u, v] : edges) {
        if (ID[u] == ID[v]) continue;
        outDeg[ID[u]]++, inDeg[ID[v]]++;
    }

    int source = 0, sink = 0, interm = 0;
    for(int i = 1; i <= ptr; i++) {
        if(outDeg[i] == 1 and inDeg[i] == 1) interm++;
        else if(outDeg[i] == 1 && inDeg[i] == 0) source++;
        else if(outDeg[i] == 0 && inDeg[i] == 1) sink++;
    }

    int id0 = ID[0];
    bool is0Source = outDeg[id0] == 1 && inDeg[id0] == 0;
    bool is_snake = (source == 1 && sink == 1 && interm == ptr - 2 && is0Source);
    bool singleScc = ptr == 1 && id0 > 0;
    bool ok = is_snake or singleScc;
    cout << (ok?"YES\n": "NO\n");
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while(t--) {
        cout << "Case "<<++cs <<": ";
        solve();
    }

}
