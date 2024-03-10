#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

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

  // number of nodes, source, sink
  Dinic(int n, int s, int t) : n(n), s(s), t(t) {
    adj.resize(n + 100), lvl.resize(n + 100), ptr.resize(n + 100);
  }

  // directed edge from v  to u (not u to v)
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

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  map<string, int> ID;
  ID["XXL"] = 1, ID["XL"] = 2;
  ID["L"] = 3, ID["M"] = 4;
  ID["S"] = 5, ID["XS"] = 6;

  int t, cs = 0;
  cin >> t;

  while (t--) {
    cout << "Case " << ++cs << ": ";
    int n, m;
    cin >> n >> m;

    int source = n * 6 + m + 1;
    int des = n * 6 + m + 2;
    Dinic dinic(n * 6 + m + 100, source, des);

    for (int i = 1; i <= m; i++) {
      string s1, s2;
      cin >> s1 >> s2;
      for (int col = 0; col < n; col++) {
        dinic.add_edge(col * 6 + ID[s1], n * 6 + i, 1);
        dinic.add_edge(col * 6 + ID[s2], n * 6 + i, 1);
      }
    }

    for (int i = 1; i <= 6 * n; i++) dinic.add_edge(source, i, 1);
    for (int i = 1; i <= m; i++) dinic.add_edge(n * 6 + i, des, 1);

    cout << (dinic.flow() == m ? "YES" : "NO") << "\n";
  }
}

