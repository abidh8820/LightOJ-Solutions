#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 202;
const LL INF = 1e17;
LL cost[N], dist[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ":\n";
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) cin >> cost[i];

        int m;
        cin >> m;

        vector<tuple<int, int, int>> edges(m);
        for (auto& [u, v, w] : edges)
            cin >> u >> v, w = pow(cost[v] - cost[u], 3);

        for (int i = 1; i <= n; i++) dist[i] = 2 * INF;
        dist[1] = 0;
        for (int i = 1; i < n; i++) {
            for (auto [u, v, w] : edges) {
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                }
            }
        }

        for (auto [u, v, w] : edges) {
            if (dist[v] > dist[u] + w) dist[v] = -INF;
        }

        int q;
        cin >> q;

        while (q--) {
            int des;
            cin >> des;

            if (dist[des] < 3 || dist[des] >= INF) cout << "?\n";
            else cout << dist[des] << "\n";
        }
    }
}

