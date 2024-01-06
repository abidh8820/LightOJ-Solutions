#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;

const int N = 1e6 + 7;
const int INF = 1e9 + 7;

int n, m, k;
vector<int> adj[N];

vector<bool> bfs(int s) {
    vector<bool> vis(n + 1, false);
    vis[s] = 1;
    vector<int> Q = {s};

    for (int i = 0; i < Q.size(); i++) {
        int u = Q[i];
        for (int v : adj[u]) {
            if (vis[v]) continue;
            Q.push_back(v);
            vis[v] = true;
        }
    }

    return vis;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";
        cin >> k >> n >> m;

        for (int i = 0; i <= n; i++) adj[i].clear();

        vector<int> sources;
        for (int i = 0; i < k; i++) {
            int x; cin >> x;
            sources.push_back(x);
        }

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        int mx = 0, ans = 0;
        vector<int> count(n + 1);

        for (int x: sources) {
            auto d = bfs(x);
            for (int j = 1; j <= n; j++)
                count[j] += d[j], mx = max(mx, count[j]);
        }

        for (int i = 1; i <= n; i++) {
            ans += (count[i] == mx);
        }

        cout << ans << "\n";
    }
}

