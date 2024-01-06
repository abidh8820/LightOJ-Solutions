#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e6 + 7;
int money[N];
vector<int> adj[N];
bool vis[N];

LL cnt, tot;


void dfs(int u){
    vis[u] = true;
    cnt++, tot += money[u];
    for(int v : adj[u]){
        if(!vis[v]) dfs(v);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";
        int n, m;
        cin >> n >> m;

        for (int i = 1; i <= n; i++) adj[i].clear(), vis[i] = 0;
        for (int i = 1; i <= n; i++) cin >> money[i];

        for (int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        bool ok = true;
        set<int> st;

        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue;
            tot = 0, cnt = 0, dfs(i);
            if(tot%cnt) ok = false;
            else st.insert(tot/cnt);
        }

        if(ok && st.size()==1) cout <<"Yes\n";
        else cout <<"No\n";
    }
}

