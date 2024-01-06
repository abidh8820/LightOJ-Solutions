#include <bits/stdc++.h>
using namespace std;

const int N = 500 + 7;
typedef pair<int, int> pii;

vector<pii> adj[N];
int dist[N], vis[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, c = 0;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i <= n; i++) adj[i].clear();
        priority_queue<pii> PQ;

        for (int i = 0; i < m; i++) {
            int u, v, w;  cin >> u >> v >> w;
            adj[u].push_back(pii(w, v));
            adj[v].push_back(pii(w, u));
        }

        int s;   cin >> s;

        for (int i = 0; i < n; i++) dist[i] = INT_MAX, vis[i] = 0;
        PQ.push(pii(dist[s]=0, s));

        while (!PQ.empty()) {
            auto [x, u] = PQ.top();
            PQ.pop(), vis[u] = true;

            for (auto [w, v] : adj[u]) {
                if (vis[v]) continue;
                if (max(w, dist[u]) < dist[v]) {
                    dist[v] = max(w, dist[u]);
                    PQ.push(pii(-dist[v], v));
                }
            }
        }

        cout << "Case " << ++c << ": " << endl;
        for (int i = 0; i < n; i++) {
            if (dist[i] >= INT_MAX) cout << "Impossible" << endl;
            else  cout << dist[i] << endl;
        }
    }
}

