#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
const int N = 1e5 + 7;
int dt[N], low[N], Time;

vector<int> adj[N];
vector<pii> bridges;

void findbriges(int u, int p) {
    low[u] = dt[u] = ++Time;
    for (auto v: adj[u]) {
        if (v == p) continue;
        if (dt[v]) low[u] = min(low[u], dt[v]);
        else {
            findbriges(v, u);
            if (dt[u] < low[v]) bridges.push_back(pii(min(u,v), max(u,v)));
            low[u] = min(low[u], low[v]);
        }
    }
}

int main() {

    int t, cs = 0;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        for (int i = 0; i <= n; i++) {
            adj[i].clear();
            dt[i] = low[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            int u, k;
            scanf("%d (%d) ", &u, &k);
            while (k--) {
                int v;    cin >> v;
                adj[u].push_back(v);
            }
        }

        bridges.clear();
        for(int i=0; i<n; i++) {
            if(!dt[i]) findbriges(i,i);
        }

        sort(bridges.begin(), bridges.end());
        cout << "Case " << ++cs << ":" << endl;
        cout << bridges.size() << " critical links" << endl;
        for (auto[x, y]: bridges) printf("%d - %d\n",x, y);
    }
}
