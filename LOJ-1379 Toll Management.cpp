#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<LL, LL>;

const LL N = 1e5 + 5;
vector<vector<PII>> g, gr;
vector<LL> dist, rev_dist;

const LL INF = 1e10;

void dijkstra(LL st, vector<LL>& dis, vector<vector<PII>> adj) {
    dis[st] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> PQ;
    PQ.emplace(0, st);

    while (not PQ.empty()) {
        auto [d, u] = PQ.top();
        PQ.pop();

        for (auto [v, w] : adj[u]) {
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                PQ.emplace(dis[v], v);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    LL t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";
        LL n, m, S, T, p;
        cin >> n >> m >> S >> T >> p;

        g.clear(), gr.clear();
        dist.clear(), rev_dist.clear();

        vector<tuple<LL, LL, LL>> edges;

        g.assign(n + 1, vector<PII>());
        gr.assign(n + 1, vector<PII>());

        dist.assign(n + 1, INF);
        rev_dist.assign(n + 1, INF);

        for (LL i = 1; i <= m; i++) {
            LL u, v, c;
            cin >> u >> v >> c;
            g[u].emplace_back(v, c);
            gr[v].emplace_back(u, c);
            edges.emplace_back(u, v, c);
        }

        dijkstra(S, dist, g);
        dijkstra(T, rev_dist, gr);

        LL ans = -1;
        for (auto [u, v, c] : edges) {
            LL cost = rev_dist[v] + dist[u] + c;
            if (cost > p) continue;
            ans = max(ans, c);
        }

        cout << ans << "\n";
    }
}

