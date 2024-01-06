#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;

const int N = 1e6 + 7;
vector<PII> adj[N];

pair<int, vector<int>> bfs(int s, int n) {
    vector<int> dist(n, -1), Q = {s};
    dist[s] = 0;

    for (int i = 0; i < Q.size(); i++) {
        int u = Q[i];
        for (auto [v, w] : adj[u]) {
            if (dist[v] != -1) continue;
            dist[v] = dist[u] + w;
            Q.push_back(v);
        }
    }

    int mx = -1, node = -1;
    for (int i = 0; i < n; i++) {
        if (dist[i] > mx) mx = dist[i], node = i;
    }

    return make_pair(node, dist);
}

int main() {
    int t, cs = 0;

    cin >> t;
    while (t--) {
        cout << "Case " << ++cs << ": ";
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) adj[i].clear();

        for (int i = 1; i < n; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }

        auto [u, dist1] = bfs(1, n);
        auto [v, dist2] = bfs(u, n);
        cout << dist2[v] << endl;
    }
}

