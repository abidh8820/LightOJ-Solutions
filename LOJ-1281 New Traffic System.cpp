#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
using Ti = tuple<int, int, int>;

const int N = 1e5 + 7;
vector<PII> g[N];
vector<PII> extra[N];

LL dist[N][11];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";
        int n, m, k, d;
        cin >> n >> m >> k >> d;

        for (int i = 0; i < n; i++) g[i].clear(), extra[i].clear();

        memset(dist, 0x03, sizeof dist);

        for (int i = 1; i <= m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            g[u].emplace_back(v, w);
        }

        for (int i = 0; i < k; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            extra[u].emplace_back(v, w);
        }

        dist[0][0] = 0;
        priority_queue<Ti, vector<Ti>, greater<Ti>> PQ;
        PQ.emplace(0, 0, 0);

        int ans = -1;
        while (!PQ.empty()) {
            auto [dd, u, kth] = PQ.top();
            PQ.pop();

            if (u == n - 1) {
                ans = dd;
                break;
            }

            for (auto [v, w] : g[u]) {
                if (dist[v][kth] > dist[u][kth] + w) {
                    dist[v][kth] = dist[u][kth] + w;
                    PQ.emplace(dist[v][kth], v, kth);
                }
            }

            for (auto [v, w] : extra[u]) {
                if (kth == d) break;
                if (dist[v][kth + 1] > dist[u][kth] + w) {
                    dist[v][kth + 1] = dist[u][kth] + w;
                    PQ.emplace(dist[v][kth + 1], v, kth + 1);
                }
            }
        }

        if (ans == -1) cout << "Impossible\n";
        else cout << ans << "\n";
    }
}

