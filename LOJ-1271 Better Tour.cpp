#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 50007;
const int INF =  1e9;
vector<int> adj[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ":\n";
        int n; cin >> n;

        vector<int> order(n);
        for(int i = 1; i < N; i++) adj[i].clear();;
        for(int i = 0; i < n; i++) cin >> order[i];

        for(int i = 1; i < n; i++){
            adj[order[i]].push_back(order[i - 1]);
            adj[order[i - 1]].push_back(order[i]);
        }

        vector<int> Q, dist(N + 1, INF);
        Q.push_back(order[n - 1]), dist[order[n - 1]] = 0;

        for(int i = 0; i < Q.size(); i++){
            int u = Q[i];
            for(int v : adj[u]){
                if(dist[v] != INF) continue;
                dist[v] = dist[u] + 1;
                Q.push_back(v);
            }
        }

        vector<int> path;
        int cur = order[0];

        while(true){
            path.push_back(cur);
            if(cur == order[n - 1]) break;
            PII best = PII(INF, INF);
            for(int v : adj[cur]) best = min(best, PII(dist[v], v));
            cur = best.second;
        }

        for(int x : path) cout << x << " ";
        cout << '\n';

    }
}

