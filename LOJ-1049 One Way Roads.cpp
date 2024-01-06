#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;

const int N = 1e6 + 7;
bool vis[N];

vector<int> adj[N], ring;

void dfs(int u) {
    vis[u] = true;
    ring.push_back(u);

    for (int v : adj[u]) {
        if (!vis[v]) dfs(v);
    }
}

int main() {
    int t, cs = 0;

    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";

        int n;
        cin >> n;

        map<int, int> cost[n + 1];
        for (int i = 1; i <= n; i++) {
            adj[i].clear(), vis[i] = false;
        }

        for (int i = 0; i < n; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back(v);
            adj[v].push_back(u);
            cost[v][u] = w;
        }

        ring.clear(), dfs(1);

        LL cost1 = 0, cost2 = 0;
        for (int i = 0; i < n; i++) {
            cost1 += cost[ring[i]][ring[(i + 1) % n]];
            cost2 += cost[ring[(i + 1) % n]][ring[i]];
        }
        cout << min(cost1, cost2) << endl;
    }
}

