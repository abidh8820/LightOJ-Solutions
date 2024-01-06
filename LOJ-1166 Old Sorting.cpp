#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;

const int N = 1005;
vector<int> adj[N];
int a[N];
bool vis[N];

void dfs(int u) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v]) dfs(v);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) adj[i].clear();
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            adj[i].push_back(a[i]);
        }

        int cnt = 0;

        memset(vis, false, sizeof vis);

        for (int i = 1; i <= n; i++) {
            if (!vis[i]) dfs(i), cnt++;
        }

        cout << n - cnt << "\n";
    }
}

