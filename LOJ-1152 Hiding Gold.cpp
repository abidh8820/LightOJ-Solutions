#include <bits/stdc++.h>
using namespace std;

struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, - 1};
struct Dinic {
    const long long flow_inf = 1e18;
    vector<FlowEdge> edg;
    vector<vector<int>> adj;

    int n, m = 0, s, t;
    vector<int> lvl, ptr;
    queue<int> q;
    
    // number of nodes, source, sink
    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n + 100), lvl.resize(n + 100), ptr.resize(n + 100);
    }
    
    //directed edge from v  to u (not u to v)
    void add_edge(int v, int u, long long cap) {
        edg.emplace_back(v, u, cap);
        edg.emplace_back(u, v, 0);
        adj[v].push_back(m++);
        adj[u].push_back(m++);
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();  q.pop();
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
            if (lvl[v] + 1 != lvl[u] || edg[id].cap - edg[id].flow < 1) continue;
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
/*
 **directed edge from v  to u (not u to v)
 ** to find matching edges go over all edges  where s!=u && s !=v && t!=u && t!=v and find flow of 1 
*/

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while(t--) {
        cout <<"Case "<<++cs <<": ";
        int n, m;
        cin >> n >> m;

        vector<string> grid(n);
        for(int i = 0; i < n; i ++) cin >> grid[i];


        int source = n * m + 1, sink = source + 1;
        Dinic graph(n * m + 5, source, sink);

        set<int> oddGolds, evenGolds;
        int totalGold = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '*') totalGold++;
                if((i + j) % 2 == 0 || grid[i][j]=='o') continue;
                for(int k = 0; k < 4; k++){
                    int x = i + dx[k], y = j + dy[k];
                    if(x < 0 or x >= n or y < 0 or y >= m or grid[x][y] == 'o') continue;
                    graph.add_edge(i * m + j + 1, x * m + y + 1, 1);
                    oddGolds.emplace(i * m + j + 1);
                    evenGolds.emplace(x * m + y + 1);
                }                
            }
        }

        for(int x : oddGolds) graph.add_edge(source, x, 1);
        for(int x : evenGolds) graph.add_edge(x, sink, 1);
        cout <<  totalGold - graph.flow() << "\n";

    }
}