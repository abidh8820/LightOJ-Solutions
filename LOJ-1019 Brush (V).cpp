#include "bits/stdc++.h"
using namespace std;

const int N = 105;
typedef pair<int, int> pii;

vector<pii> adj[N];
int dist[N][N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, c = 0;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = 1e8;
            }
        }

        for (int i = 1; i <= m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            dist[u][v] = min(dist[u][v], w);
            dist[v][u] = min(dist[v][u], w);
        }

        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        cout << "Case " << ++c << ": ";
        if (dist[1][n] == 1e8)
            cout << "Impossible" << endl;
        else
            cout << dist[1][n] << endl;
    }
}

