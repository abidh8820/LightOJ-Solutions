#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int INF = 1e9 + 7;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, cs = 0;
    cin >> t;

    while (t--) {
        cout << "Case " << ++cs << ": ";
        int n, m;
        cin >> n >> m;

        vector<tuple<int,int,int>> edges(m);
        for(int i = 0 ; i < m; i++){
            auto&[v, u, w] = edges[i];
            cin >> u >> v >> w;
        }

        vector<int> dist(n, INF);
        vector<int> good(n, 0), vis(n, 0);
        dist[0] = 0;

        for(int i = 0; i <= 2 * n; i++){
            for(auto[u, v, w] : edges){
                if(dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w; 
                    if(i >= n) {
                        good[v] = true;
                    }
                }
            }
        }

        for(int i = 0; i <= 2 * n; i++){
            for(auto[u, v, w] : edges) good[v] |= good[u];
        }

        vector<int> ans;
        for(int i = 0 ; i < n; i++){
            if(good[i]) ans.push_back(i);
        }

        if(ans.empty()) cout <<"impossible\n";
        else {
            sort(ans.begin(), ans.end());
            for(int i = 0; i < ans.size(); i++) cout << ans[i] << " \n"[i== ans.size() - 1];
        }
    }
}

