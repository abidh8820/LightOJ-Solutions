#include <bits/stdc++.h>
using namespace std;

struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const long long flow_inf = 1e18;
    vector<FlowEdge> edg;
    vector<vector<int>> adj;

    int n, m = 0, s, t;
    vector<int> lvl, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n + 100), lvl.resize(n + 100), ptr.resize(n + 100);
    }

    void add_edge(int v, int u, long long cap) {
        edg.emplace_back(v, u, cap);
        edg.emplace_back(u, v, 0);
        adj[v].push_back(m++);
        adj[u].push_back(m++);
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edg[id].cap - edg[id].flow < 1) continue;
                if (lvl[edg[id].u] != -1) continue;
                lvl[edg[id].u] = lvl[v] + 1, q.push(edg[id].u);
            }
        }
        return lvl[t] != -1;
    }

    long long dfs(int v, long long pushed) {
        if (pushed == 0) return 0;
        if (v == t) return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid], u = edg[id].u;
            if (lvl[v] + 1 != lvl[u] || edg[id].cap - edg[id].flow < 1)
                continue;
            long long tr = dfs(u, min(pushed, edg[id].cap - edg[id].flow));
            if (tr == 0) continue;
            edg[id].flow += tr, edg[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long flow() {
        long long f = 0;
        while (true) {
            fill(lvl.begin(), lvl.end(), -1);
            lvl[s] = 0, q.push(s);
            if (!bfs()) break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) f += pushed;
        }
        return f;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";

        int n, m;
        cin >> n >> m;

        vector<tuple<int, int, int>> boys(n);
        vector<tuple<int, int, int>> girls(m);
        for (auto& [x, y, z] : boys) cin >> x >> y >> z;
        for (auto& [x, y, z] : girls) cin >> x >> y >> z;


        int source = n + m + 2;
        int sink = n + m + 3;

        Dinic G(n + m + 10, source, sink);
        for (int i = 1; i <= n; i++) G.add_edge(source, i, 1);
        for (int i = 1; i <= m; i++) G.add_edge(n + i, sink, 1);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                auto [x1, y1, z1] = boys[i - 1];
                auto [x2, y2, z2] = girls[j - 1];
                if (abs(x1 - x2) > 12 or abs(y1 - y2) > 5 or (z1 != z2)) continue;
                G.add_edge(i, j + n, 1);
            }
        }

        cout << G.flow() << "\n";
    }
}

