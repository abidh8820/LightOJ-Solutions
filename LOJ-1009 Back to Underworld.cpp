#include <bits/stdc++.h>
using namespace std;

using LL = long long;

const int N = 1e5 + 7;
vector<int> adj[N];
bool vis[N];
int black, white;

void dfs(int u, bool col) {
    if (col) white++;
    else black++;
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v]) dfs(v, !col);
    }
}

int main() {
    int t, cs = 0;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> edges(n);
        set<int> nodes;

        for (int i = 0; i < n; i++) {
            auto& [x, y] = edges[i];
            scanf("%d %d", &x, &y);
            nodes.insert(x);
            nodes.insert(y);
        }

        for (int x : nodes) {
            adj[x].clear();
            vis[x] = false;
        }

        for (auto [x, y] : edges) {
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        int ans = 0;
        for (int x : nodes) {
            if (vis[x]) continue;
            black = 0, white = 0;
            dfs(x, 0);
            ans += max(white, black);
        }

        printf("Case %d: %d\n", ++cs, ans);
    }
}

