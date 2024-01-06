#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;

const int N = 15;
int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

int dist[N][N];
bool vis[N][N];

int main() {
    int t, cs = 0;

    cin >> t;
    while (t--) {
        cout << "Case " << ++cs << ": ";

        int n, m;
        cin >> n >> m;
        char grid[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        int ans = 1e9;

        for (int sx = 0; sx < n; sx++) {
            for (int sy = 0; sy < m; sy++) {
                memset(vis, 0, sizeof vis);
                memset(dist, 0x0b, sizeof dist);

                dist[sx][sy] = 0;
                vis[sx][sy] = 1;

                vector<PII> Q = {{sx, sy}};

                for (int i = 0; i < Q.size(); i++) {
                    auto [ux, uy] = Q[i];

                    for (int k = 0; k < 8; k++) {
                        int vx = ux + dx[k];
                        int vy = uy + dy[k];
                        if (vx < 0 || vx >= n || vy < 0 || vy >= m) continue;
                        if (!vis[vx][vy]) {
                            Q.push_back({vx, vy});
                            vis[vx][vy] = true;
                            dist[vx][vy] = dist[ux][uy] + 1;
                        }
                    }
                }

                int need = 0;
                for (int x = 0; x < n; x++) {
                    for (int y = 0; y < m; y++) {
                        if (grid[x][y] == '.') continue;
                        int g = grid[x][y] - '0';
                        need += (dist[x][y] + g - 1) / g;
                    }
                }
                ans = min(ans, need);
            }
        }

        if (ans > 50000) cout << "-1\n";
        else cout << ans << "\n";
    }
}

